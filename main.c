#include<stdio.h>

struct ArrayAdt
{
    int capacity;
    int lastindex;
    int *ptr;

};

struct ArrayAdt*createArray(int capacity);
int getItem(struct ArrayAdt*arr , int index);
int setItem(struct ArrayAdt*arr , int index , int item);
int editItem(struct ArrayAdt*arr , int index , int item);
int countItems(struct ArrayAdt*arr);
int removeItem(struct ArrayAdt*arr , int index);
int searchItem(struct ArrayAdt*arr , int item);


struct ArrayAdt*createArray(int capacity)
{
    struct ArrayAdt* arr;
    arr = (struct ArrayAdt*)malloc(sizeof(struct ArrayAdt));
    arr->capacity = capacity;
    arr->lastindex = -1;
    arr->ptr = (int*)malloc(sizeof(int)*arr->capacity);
    return(arr);
};

int getItem(struct ArrayAdt*arr , int index)
{
    if(arr->lastindex < index || index<0)
    {
        printf("Invalid Index");
        return(-1);
    }
    else
    {

        return(arr->ptr[index]);
    }

}


int setItem(struct ArrayAdt*arr , int index , int item)
{
    //check array is full
    if(arr->lastindex == arr->capacity-1)
    {
        printf("OverFlow");
        return(0);
    }
    if(index < 0 || index >arr->lastindex+1)
    {
        printf("Invalid Index");
        return(0);
    }
    if(index<=arr->lastindex)
    {
        arr->lastindex = arr->lastindex+1;
        int i = arr->lastindex;
        while(i!=index)
        {
            //shifting
            arr->ptr[i] = arr->ptr[i-1];
            i--;

        }
        arr->ptr[index] = item;
    }
    if(index == arr->lastindex+1)
    {
        arr->lastindex = arr->lastindex+1;
        arr->ptr[arr->lastindex] = item;
        return(1);
    }

}

int editItem(struct ArrayAdt*arr , int index , int item)
{
    if(index < 0 || index > arr->lastindex)
    {
        printf("Invalid index");
        return(0);
    }
    else
    {
        arr->ptr[index] = item;
        return(1);
    }


}

int countItems(struct ArrayAdt*arr)
{
    return(arr->lastindex+1);

}

int removeItem(struct ArrayAdt*arr , int index)
{
    if(index <0 || index > arr->lastindex)
    {
        printf("Invalid Index");
        return(0);
    }

    if(index < arr->lastindex)
    {
        int i;
        i = index;
        while(i!=arr->lastindex)
        {
            arr->ptr[i] = arr->ptr[i+1];
            i++;
        }
        arr->lastindex = arr->lastindex-1;
    }
    if(index==arr->lastindex)
    {
        arr->lastindex = arr->lastindex-1;
        return(1);

    }


}


int searchItem(struct ArrayAdt*arr , int item)
{
    if(arr->lastindex==-1)
    {

        printf("Array is Empty..!");
        return(-1);
    }
    for(int i=0;i<=arr->lastindex;i++)
    {

        if(arr->ptr[i]==item)
        {
            return(i);
        }
    }

    return(-1);

}

int main()
{
    struct ArrayAdt *arr;
    arr = createArray(5);
    setItem(arr,0,10);
    setItem(arr,1,20);
    setItem(arr,2,30);

    for(int i=0;i<countItems(arr);i++)
        printf("%d \n" , getItem(arr , i));

     printf("\nAfter remove item  : ");
    removeItem(arr , 2);

    for(int i=0;i<countItems(arr);i++)
   {
       printf("%d " , getItem(arr , i));
   }

   printf("\nTotal item is: ");
   int total = countItems(arr);
   printf("%d" , total);


   printf("\n");
   int item = getItem(arr , 4);
    if(item!=-1)
    {
        printf("%d" , item);
    }


    return(1);
}


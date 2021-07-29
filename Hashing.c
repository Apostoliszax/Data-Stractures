#include <stdio.h>

#define size 20

int arr[size];

void initialize()
{
  int i;
  for (i = 0; i < size; i++)
    arr[i] = -1;
}

void add(int value)
{
  int key = value % size;

  if (arr[key] == -1)
  {
    arr[key] = value;
    printf("%d add at arr[%d]\n", value, key);
  }
  else
  {
    printf("Collision : arr[%d] has element %d already!\n", key, arr[key]);
    printf("Unable to add %d\n", value);
  }
}

void del(int value)
{
  int key = value % size;
  if (arr[key] == value)
    arr[key] = -1;
  else
    printf("%d not present in the hash table\n", value);
}

void search(int value)
{
  int key = value % size;
  if (arr[key] == value)
    printf("Search Found\n");
  else
    printf("Search Not Found\n");
}

void print()
{
  int i;
  for (i = 0; i < size; i++)
    printf("arr[%d] = %d\n", i, arr[i]);
}

int main()
{
  initialize();

  add(10); //key = 10 % 20 ==> 10
  add(4);  //key = 4 % 20  ==> 4
  add(2);  //key = 2 % 20  ==> 2
  add(1);  //key = 1 % 20  ==> 1
  add(9);  //key = 9 % 20  ==> 9
  add(11); //key = 11 % 20 ==> 11
  add(14); //key = 14 % 20 ==> 14
  add(17); //key = 17 % 20 ==> 17
  add(3);  //key = 3 % 20  ==> 3
  printf("Hash table\n");
  print();
  printf("\n");

  printf("Deleting value 10..\n");
  del(10);
  printf("After the deletion hash table\n");
  print();
  printf("\n");

  printf("Deleting value 5..\n");
  del(5);
  printf("After the deletion hash table\n");
  print();
  printf("\n");

  printf("Deleting value 11..\n");
  del(11);
  printf("After the deletion hash table\n");
  print();
  printf("\n");

  printf("Deleting value 5..\n");
  del(3);
  printf("After the deletion hash table\n");
  print();
  printf("\n");

  printf("Searching value 4..\n");
  search(4);
  printf("Searching value 10..\n");
  search(10);
  printf("Searching value 1..\n");
  search(1);
  printf("Searching value 5..\n");
  search(5);

  return 0;
}
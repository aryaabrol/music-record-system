#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char name[50];
    char genre[50];
    int year;
    char artist[50];
    int rating;
    struct node *next;
}*Node,*f=NULL,x;

void add()
{
    system("cls");
    Node =(struct node*)malloc(sizeof(struct node));
    if(Node==NULL)
        printf("memory cannot be allocated");

	if(f==NULL)
    {
        printf("enter song name:");
        scanf("%s",&x.name);
        printf("enter genre:");
        scanf("%s",&x.genre);
        printf("enter year of release:");
        scanf("%d",&x.year);
        while(x.year>2019)
        {
        printf("Invalid Year\n");
        printf("Enter again:");
        scanf("%d",&x.year);
        }
        printf("enter artist name:");
        scanf("%s",&x.artist);
        printf("enter rating(Rating should be between 1-5):");
        scanf("%d",&x.rating);
        while(x.rating>5)
        {printf("invalid\n");
         printf("Enter rating again:");
         scanf("%d",&x.rating);}

        strcpy(Node->name, x.name);
        strcpy(Node->genre,x.genre);
        strcpy(Node->artist,x.artist);
        Node->year=x.year;
        Node->rating=x.rating;
        Node->next=NULL;
        f=Node;

    }

	else
	{
	printf("enter song:");
	scanf("%s",&x.name);
	printf("enter genre:");
	scanf("%s",&x.genre);
	printf("enter year of release:");
	scanf("%d",&x.year);
	while(x.year>2019)
    {
        printf("Invalid Year\n");
        printf("Enter again:");
        scanf("%d",&x.year);
    }
	printf("enter artist name:");
	scanf("%s",&x.artist);
	printf("enter rating(Rating should be between 1-5):");
    scanf("%d",&x.rating);
    while(x.rating>5)
    {printf("invalid\n");
     printf("Enter rating again:");
     scanf("%d",&x.rating);}


	strcpy(Node->name, x.name);
	strcpy(Node->genre,x.genre);
	strcpy(Node->artist,x.artist);
	Node->year=x.year;
	Node->rating=x.rating;

	struct node *temp;
    temp=f;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=Node;
	Node->next =NULL ;
	}
}

void del()
{
   system("cls");
   char n[50];
   struct node *temp, *prev;
   temp = f;
   int c=0;

   printf("\nWhat is the name of the Song wish to delete?\n");
   scanf("%s",&n);

   // First, locate the node that contains the item.
    if(f==NULL)
   {
      printf("Linked List not initialized\n");
      return;
   }

   while (temp->next != NULL )
   {
      if(strcmp(temp->name,n)==0)
      {
         c=1;
         break;
      }
      prev = temp;
      temp = temp->next;
   }

   if(strcmp(temp->name,n)==0)
       c=1;


   // Now take care of deleting it.
   if (c==1)
   {
   if ( temp != NULL )
   {
      if ( temp == f )
      {
         f = temp->next;
      }
      else
      {
         prev->next = temp->next;
      }
      free(temp);
      printf("%s was deleted successfully\n", n);
   }
   }

   else
    printf("%s not found in the playlist\n",n);
}

void update()
{
   system("cls");
   char old[50],a[50];
   int ch,b;

   if(f==NULL)
   {
      printf("PlayList not initialized\n");
      return;
   }

   printf("enter the song to be altered\n");
   scanf("%s",&old);
   struct node* current;
   current = f;
   while(current->next!=NULL) {
      if(strcmp(current->name,old)==0)
      {

         printf("enter the data to be changed 1.)song 2.)genre 3.)year 4.)artist 5.)rating\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:printf("enter the new song name\n");
                    scanf("%s",&a);
                    strcpy(current->name,a);
                    break;

             case 2:printf("enter the new genre name\n");
                    scanf("%s",&a);
                    strcpy(current->genre,a);
                    break;

            case 3:printf("enter the year\n");
                    scanf("%d",&b);
                    current->year=b;
                    break;

            case 4:printf("enter artist name\n");
                    scanf("%s",&a);
                    strcpy(current->artist,a);
                    break;


            case 5:printf("enter the new rating\n");
                    scanf("%d",&b);
                    current->rating=b;
                    break;

            }
         printf("\nChanges made successfully.\n");
         return;
      }

      current = current->next;

   }

   if(strcmp(current->name,old)==0)
      {

         printf("enter the data to be changed 1.)song 2.)genre 3.)year 4.)artist 5.)rating\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:printf("enter the new song name\n");
                    scanf("%s",&a);
                    strcpy(current->name,a);
                    break;

             case 2:printf("enter the new genre name\n");
                    scanf("%s",&a);
                    strcpy(current->genre,a);
                    break;

            case 3:printf("enter the year\n");
                    scanf("%d",&b);
                    current->year=b;
                    break;

            case 4:printf("enter artist name\n");
                    scanf("%s",&a);
                    strcpy(current->artist,a);
                    break;


            case 5:printf("enter the new rating\n");
                    scanf("%d",&b);
                    current->rating=b;
                    break;

            }
         printf("\nChanges made successfully.\n");
         return;
      }

   printf("%s does not exist in the list\n", old);
}

void display()
{
    system("cls");
    if(f==NULL)
    printf("playlist not initiated\n");

    else
    {
    int i=1;
    Node=f;
    while(Node->next!=NULL)
    {
        printf("%d.) ",i);
        printf("Song Name:%s\n",Node->name);
        printf("Artist Name:%s\n",Node->artist);
        printf("Genre:%s\n",Node->genre);
        printf("Year of Release:%d\n",Node->year);
        printf("Rating:%d\n",Node->rating);
        printf("\n");
        i++;
        Node=Node->next;
    }
        printf("%d.) ",i);
        printf("Song Name:%s\n",Node->name);
        printf("Artist Name:%s\n",Node->artist);
        printf("Genre:%s\n",Node->genre);
        printf("Year of Release:%d\n",Node->year);
        printf("Rating:%d\n",Node->rating);
        printf("\n");

    }
}

void search()
{

     char old[50],a[50];
   int ch,b,j=0;

   if(f==NULL)
   {
      printf("Playlistlist not initialized\n");
      return;
   }


   printf("enter the song to be searched\n");
   scanf("%s",&old);
   struct node* current;
   current = f;
   while(current->next!=NULL) {
      if(strcmp(current->name,old)==0)
      {
        printf("Song Name:%s\n",current->name);
        printf("Artist Name:%s\n",current->artist);
        printf("Genre:%s\n",current->genre);
        printf("Year of Release:%d\n",current->year);
        printf("Rating:%d\n\n\n",current->rating);
        j=1;
        return;
      }

     current=current->next;
     }
     if(strcmp(current->name,old)==0)
      {
        printf("Song Name:%s\n",current->name);
        printf("Artist Name:%s\n",current->artist);
        printf("Genre:%s\n",current->genre);
        printf("Year of Release:%d\n",current->year);
        printf("Rating:%d\n\n\n",current->rating);
        j=1;
        return;
      }

     if(j!=1)
      printf("not found\n\n");

}

void searchbyartist()
{

char old[50],a[50];
   int b,j=0,i=1;

   if(f==NULL)
   {
      printf("Linked List not initialized\n");
      return;
   }

   printf("enter the artist name\n");
   scanf("%s",&old);
   struct node* current;
   current = f;
   printf("The songs by %s are:\n",old);
   while(current->next!=NULL){
      if(strcmp(current->artist,old)==0)
      {
        printf("%d.)%s\n",i,current->name);
        i++;
        j=1;
       }

     current=current->next;
     }

      if(strcmp(current->artist,old)==0)
      {
        printf("%d.)%s\n",i,current->name);
        j=1;
       }
      if(j!=1)
      printf("not found\n");

}

void searchbyyear()
{

char a[50];
   int ch,b,j=0,old;

   if(f==NULL)
   {
      printf("Linked List not initialized\n");
      return;
   }

   printf("enter the Year\n");
   scanf("%d",&old);
   struct node* current;
   current = f;
   printf("Songs of the year %d are:\n",old);
   while(current->next!=NULL){
      if(current->year==old)
      {
        printf("%s\n",current->name);
        j=1;
       }

     current=current->next;
     }

      if(current->year==old)
      {
        printf("%s\n",current->name);
        j=1;
       }
      if(j!=1)
      printf("not found\n\n");

}

void searchbyrating()
{

char a[50];
   int ch,b,j=0,old;

   if(f==NULL)
   {
      printf("Linked List not initialized\n");
      return;
   }

   printf("enter rating\n");
   scanf("%d",&old);
   struct node* current;
   current = f;
   printf("Songs having %d star rating are:\n",old);
   while(current->next!=NULL){
      if(current->rating==old)
      {
        printf("%s\n",current->name);
        j=1;
       }

     current=current->next;
     }

      if(current->rating==old)
      {
        printf("%s\n",current->name);
        j=1;
       }
      if(j!=1)
      printf("not found\n\n");

}

int main()
{
        int c,d=1;
       // printf("---------------Welcome to Music Record System-------------\n");
        while(d==1)
        {

            printf("---------------Welcome to Music Record System-------------\n");
            printf("\n\t Enter your choice \n\t 1.)Add Music \n\t 2.)Delete Music \n\t 3.)Update music \n\t 4.)Display Music\n\t 5.)Search for music\n\t 6.)Exit\n\t ");
            scanf("%d",&c);
        switch(c)
        {
        case 1:add();
               printf("Do you want to continue?:\n 1.)Yes\n 2.)No\n");
               scanf("%d",&d);
               system("cls");
               break;

        case 2: del();
               printf("Do you want to continue?:\n 1.)Yes\n 2.)No\n");
               scanf("%d",&d);
               system("cls");
                break;
        case 3:
                update();
                printf("Do you want to continue?:\n 1.)Yes\n 2.)No\n");
               scanf("%d",&d);
               system("cls");
                break;

        case 4:display();
               printf("Do you want to continue?:\n 1.)Yes\n 2.)No\n");
               scanf("%d",&d);
               system("cls");
               break;
                //artist
                //genre
                //rating
                //name
                //break;

        case 5:
               {system("cls");
                int a;
               printf("\n\nenter your choice?\n1)Search song Information\n2)Search song by artist\n3)search song by year\n4)Search highest rated songs\n");
               scanf("%d",&a);
               switch(a)
               {
                   case 1:search();
                          break;

                   case 2:searchbyartist();
                          break;

                   case 3:searchbyyear();
                          break;

                   case 4:searchbyrating();
                          break;

               }
               printf("Do you want to continue?:\n 1.)Yes\n 2.)No\n");
               scanf("%d",&d);
               system("cls");
               break;}


        case 6:printf("THANK YOU\n");
               return(0);

        default:
            printf("Wrong choice\n please try again\n");



        }


    }
    }

/*

6 September 2022

Create a file marks (.txt or .dat) to store marks (assuming same subjects for all branch students) of registered students of a university. 
The file should store student ID, marks of DBMS, DS, C, TOTAL, and PERCENTAGE The following constraints should be satisfied to store the information in student table
    - Marks of only the registered students are allowed to store in the table.
    - The maximum marks of each subject cannot exceed 100.

Perform the following query operation using the student and marks information. (NOTE: Create a menu driven program for better understanding)
    i. Insert marks of all the registered students.
    ii. Updating marks of one subject should also update TOTAL and PERCENTAGE marks.
    iii. Deletion of a student record from the student file should also delete his marks records from the marks file as the student is no longer a registered student.
    iv. Show the marks list (Marks of all subjects, TOTAL, and PERCENTAGE) of a student using his student ID.
    v. Search the students with PERCENTAGE above a threshold.
    vi. Search the students of a particular BRANCH with PERCENTAGE above a threshold.

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
    int id;
    int registered;
    int dbms;
    int ds;
    int c;
    int total;
    float percent;
};

void Menu(int choice, FILE *fptr,struct student s[10]);

int main(){
    FILE *fptr = NULL;
    struct student s[10];    
    int choice = 1;
    while(choice){
        printf("Press '1' to fill marks of 10 student entries\nPress '2' to modify marks\nPress '3' to delete student records\nPress '4' to view the file\nPress '5' to search with threshold\nPress '6' to search registered students with threshold\nPress '0' to exit\n");
        scanf("%d",&choice);
        fflush(stdin);
        Menu(choice,fptr,s);
    }
    return 0;
}

void Menu(int choice, FILE *fptr,struct student s[10]){
    int i,j;
    switch(choice){
        case 0:
            printf("Thank you for using the program!\nInfomation is stored in the file");
            break;
        case 1:
            fptr = fopen("marks.txt","w+");
            for(i=0;i<10;++i){
                fflush(stdin);
                printf("Enter ID of %dth student: ",i+1);
                scanf("%d",&s[i].id);
                printf("Press '1' if the student is registered and '0' if not registered: ");
                scanf("%d",&s[i].registered);
                if(!s[i].registered){s[i].dbms = -1;s[i].ds = -1;s[i].c = -1;s[i].total=0;s[i].percent=0;}
                else{
                    for(j=0;j<i;++j){if(s[j].id == s[i].id){printf("Duplicate ID!");exit(0);}}
                    fflush(stdin);
                    printf("Enter marks in DBMS: ");
                    scanf("%d",&s[i].dbms);
                    printf("Enter marks in DS: ");
                    scanf("%d",&s[i].ds);
                    printf("Enter marks in C: ");
                    scanf("%d",&s[i].c);
                    if(s[i].c >100 ||s[i].ds >100||s[i].dbms >100){printf("Marks cannot be greater than 100\n");exit(0);}
                    s[i].total = s[i].c + s[i].dbms + s[i].ds;
                    s[i].percent = s[i].total/3;
                }
                fwrite(&s[i],sizeof(struct student),1,fptr);
                fflush(stdin);
            }
            fclose(fptr);
            break;
        case 2:
            fflush(stdin);
            fptr = fopen("marks.txt","w+");
            printf("Enter the ID for which data needs to be changed: ");
            int c;
            scanf("%d",&c);
            printf("Press '7' to change dbms marks or '8' to change ds or '9' to change c marks: ");
            int c1;
            scanf("%d",&c1);
            printf("Enter the change: ");
            for(i=0;i<10;++i){
                if(s[i].id==c){
                    if(c1==7){scanf("%d",&s[i].dbms);}
                    else if(c1==8){scanf("%d",&s[i].ds);}
                    else if(c1==9){scanf("%d",&s[i].c);}
                    s[i].total = s[i].c + s[i].dbms + s[i].ds;
                    s[i].percent = s[i].total/3;
                    break;
                }
            }
            for(i=0;i<10;++i){fwrite(&s[i],sizeof(struct student),1,fptr);}
            fclose(fptr);
            break;
        case 3:
            fptr = fopen("marks.txt","w+");
            struct student temp = {-1,-1,-1,-1,0,0};
            printf("Enter ID of student to be deleted: ");
            int c4;
            fflush(stdin);
            scanf("%d",&c4);
            for(i=0;i<10;++i){
                if(s[i].id == c4){s[i] = temp;} 
                fwrite(&s[i],sizeof(struct student),1,fptr);
            }
            fclose(fptr);
            break;
        case 4:
            fptr = fopen("marks.txt","r");
            for(i=0;i<10;++i){while(fread(&s[i],sizeof(struct student),1,fptr)){printf("ID=> %d| DBMS=> %d| DS=> %d| C=> %d| Total=> %d/300| Percent=> %0.2f%%\n",s[i].id,s[i].dbms,s[i].ds,s[i].c,s[i].total,s[i].percent);}}
            fclose(fptr);
            break;
        case 5:
            fptr = fopen("marks.txt","r");
            printf("Enter the threshold: ");
            fflush(stdin);
            float threshold;
            scanf("%f",&threshold);
            for(i=0;i<10;++i){
                while(fread(&s[i],sizeof(struct student),1,fptr)){
                    if(s[i].percent > threshold){printf("ID=> %d| DBMS=> %d| DS=> %d| C=> %d| Total=> %d/300| Percent=> %0.2f%%\n",s[i].id,s[i].dbms,s[i].ds,s[i].c,s[i].total,s[i].percent);}
                }
            }
            fclose(fptr);
            break;
        case 6:
            fptr = fopen("marks.txt","r");
            printf("Enter the threshold: ");
            fflush(stdin);
            scanf("%f",&threshold);
            for(i=0;i<10;++i){
                while(fread(&s[i],sizeof(struct student),1,fptr)){
                    if(s[i].percent >= threshold && s[i].registered == 1){printf("ID=> %d| DBMS=> %d| DS=> %d| C=> %d| Total=> %d/300| Percent=> %0.2f%%\n",s[i].id,s[i].dbms,s[i].ds,s[i].c,s[i].total,s[i].percent);}
                }
            }
            fclose(fptr);
            break;
        default:
            printf("Enter a valid input!TRY AGAIN\n");
            break;
    }
}
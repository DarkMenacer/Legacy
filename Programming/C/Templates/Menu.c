void MENU(){
    int choice;
    printf("\n\n*--MENU--*\nPress '1' to \nPress '2' to \nPress '3' to \nPress '4' to \nPress '5' to \n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            /* Enter function here */
            int inp;
            scanf("%d",&inp);
            printf("Press '6' to \nPress '7' to \n");
            int further;
            scanf("%d",&further);
            switch(further){
                case 6:
                    printf("job done \n");
                    break;
                case 7:
                    printf("job done \n");
                    break;
            }
            printf("job done \n");
            MENU();
            break;
        case 2:
            /* Enter function here */
            printf("job done \n");
            MENU();
            break;
        case 3:
            /* Enter function here */        
            printf("job done \n");
            MENU();
            break;
        case 4:
            /* Enter function here */
            printf("job done \n");
            MENU();
            break;
        case 5:
            /* Enter function here */
            printf("job done \n");
            MENU();
            break;
        default:
            printf("Invalid Entry,Try Again");
            MENU();
    }
}
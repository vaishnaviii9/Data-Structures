#include<stdio.h>
#include<stdlib.h>
void main()
{
	int stack[10],ele;
	int i,ch,ch2,ch3,ch4,PTOP=5, STOP=4;
		
		do
		{
			printf("\n 1-PUSH");
			printf("\n 2-POP");
			printf("\n 3-Display op");
			printf("\n 4-EXIT");
			printf("\n Provide your choice");
			scanf("%d",&ch);

				switch(ch)
				{
					case 1://1-PUSH
					if(PTOP==0)
					{printf("\n Primary Stack overflow");
					}
					else
					{
					printf("\n Enter element to PUSH into primary stack");
					scanf("%d",&ele);
					stack[PTOP-1]=ele;			
					PTOP--;
					}
					break;
												
					case 2:	//2-POP					
					printf("\n On which stack you want to perform POP operation");
					printf("\n P- Primary Stack");
					printf("\n S- Secondary Stack");
					printf("\n Provide your choice");
					scanf("%c",&ch2);
					
                    switch(ch2)
                    {
                        case 'P'://POP from Primarystack
                        if(PTOP==5)
                        {
                            printf("\n Primary stack underflow");
                        }
                        else
                        {
                            if(STOP==9)
                            {
                                printf("\n Secondary stack overflow. Cannot perform POP operation");
                            }
                            else{
                                printf("\n TOP element :%d is popped out from Primarystack and pushed into Secondarystack",stack[PTOP]);
                                ele=stack[PTOP];
                                PTOP++;
                                stack[STOP+1]=ele;
                                STOP++;
                            }
                        }
                        break;
                        
                        case 'S'://POP from Secondarystack
                        if(STOP==4)
                        {
                            printf("\n Secondarystack underflow");
                        }
                        else
                        {
                            printf("\n %d is Top element of Secondarystack",stack[STOP]);
                            printf("\n Select any operation");
                            printf("\n R-Restore");
                            printf("\n D-Discard");
                            scanf("%c",&ch3);
                            switch(ch3)
                            {
                               case 'R':// R-Restore
                               if(PTOP==0)
                               {
                                   printf("\n Primarystack overflow. Cannot perform operation");
                               }
                               else
                               {
                                   printf("\n Top element :%d is popped out from Secondarystack and pushed into Primarystack",stack[STOP]);
                                   ele=stack[STOP];
                                   STOP--;
                                   stack[PTOP-1]=ele;
                                   PTOP--;
                               }
                               
                               break;
                               
                               case 'D'://D-Discard
                               printf("\n Top element: %d is discarded",stack[STOP]);
                               ele=stack[STOP];
                               STOP--;
                               break;
                            }
                            
                            
                        }
                        break;
                    }
                    break;
    
                     case 3://3-Display
                     printf("\n Which stack do you want to display");
                     printf("\n P-Primary stack ");
                     printf("\n S- Secondary stack");
                     scanf("%c",&ch4);
                            
                            switch(ch4)
                            {
                                case 'P':// Primary stack
                                if(PTOP==5)
                                {
                                    printf("\n Primary stack underflow");
                                }
                                else
                                {
                                    for(int i=PTOP; i<5; i++)
                                    {
                                        printf("\n %d",stack[i]);
                                    }
                                }
                                
                                break;
                                case 'S':// Secondary stack
                                if(STOP==4)
                                {
                                    printf("\n Secondary stack underflow");
                                }
                                else
                                {
                                    for(int i=STOP; i>4; i--)
                                    {
                                        printf("\n %d",stack[i]);
                                    }
                                }
                                
                                break;
                            }
                      
                     break;
                     case 4://4-EXIT
                     exit(0);
                     
				}
		}
		while(1);
}

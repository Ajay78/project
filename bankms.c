// CUSTOMER ACCOUNT BANK MANAGEMENT SYSTEM
//
// Copyright (C) 2015 Ajay Ingole. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 
// 1. Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.  
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.  
// 3. Neither the name of the project nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
// SUCH DAMAGE.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bankms.h"
int main_exit;
void close(void) {
	printf("\n\n  Thanks for Banking...!\n\n");
	exit(0);
}

float interest(float t,float amount,int rate) {
	float SI;
	SI=(rate*t*amount)/100.0;
	return (SI);
}

    /*code for creating new account*/
void new_acc() {
	system("clear");
	FILE *fp;
	account_no:
	fp = fopen("record.dat","a+");
	
	
	printf("\n\t\t\t\t ADD RECORD ");
	printf("\n\n\tEnter the account number:");
	scanf("%d", &check.acc_no);
	while(fscanf(fp,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.address, add.pancard, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year)!=EOF)
		if (check.acc_no == add.acc_no) {
			/*if exist then take another number*/
			printf("\tAccount no. already in use!\n");
			inval:
			printf("\n\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
			scanf("%d",&main_exit);
			if(main_exit==0) {
			system("clear");
			goto account_no;
		}
		else if (main_exit==1) {
			system("clear");
			main_menu();
		}
			else if (main_exit==2) {
				system("clear");
				close();
			}
				else {
					printf("\nInvalid!\a");
					system("clear");
					goto inval;
				}
		}
        	/*save the account number

   			 *and take another data*/
	add.acc_no = check.acc_no;
	
	printf("\n\tEnter the name:");
	scanf("%s", add.name);
	printf("\n\tEnter the date of birth(dd/mm/yyyy):");
	scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);
	printf("\n\tEnter today's date(dd/mm/yyyy):");
	scanf("%d/%d/%d", &add.deposit.day, &add.deposit.month, &add.deposit.year);
	printf("\n\tEnter the age:");
	scanf("%d", &add.age);
	printf("\n\tEnter the address:");
	scanf("%s", add.address);
	printf("\n\tEnter the pancard number:");
	scanf("%s", add.pancard);
	printf("\n\tEnter the phone number: ");
	scanf("%lld", &add.phone);
	printf("\n\tEnter the amount to deposit:$");
	scanf("%f", &add.amt);
	printf("\n\tType of account by typing text like Saving:\n\t#Saving\n\t\t#Current\n\t\t#Fixed1(for 1 year)\n\t\t#Fixed2(for 2 years)\n\t\t#Fixed3(for 3 years)\n\n\t\tEnter your choice:");
	scanf("%s", add.acc_type);
	
	fprintf(fp,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d \n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.pancard, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
	fclose(fp);

	printf("\n\tAccount created successfully!");
	invalid:
	printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	if (main_exit==1) {
      		/*goto main menu*/
		system("clear");
		main_menu();
		
	}
	else if(main_exit==0) {
          /*exit the programm*/
          system("clear");
          close();
	}
		else {
			printf("\nInvalid!\a");
			system("clear");
			goto invalid;
		}	
}


	/*code to update existing data*/
void update(void) {
	system("clear");
	int choice,test=0;
	FILE *old,*newrec;
	old=fopen("record.dat","r");
	newrec=fopen("new.dat","w");

	printf("\n\n\tEnter the account no. of the customer whose info you want to change:");
	scanf("%d", &upd.acc_no);
	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.address, add.pancard, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year)!=EOF) {
		if (add.acc_no == upd.acc_no) {
			test = 1;
			valid:
			printf("\n\tWhich information do you want to change?\n\t1.Address\n\t2.Phone\n\n\tEnter your choice(1 for address and 2 for phone):");
			scanf("%d", &choice);
		
			if(choice == 1) {
				printf("\tEnter the new address:");
				scanf("%s",upd.address);
                	
				fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d \n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, upd.address, add.pancard, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
				printf("\tChanges saved!");
			}
			else if(choice == 2) {
			printf("\tEnter the new phone number:");
			scanf("%lld", &upd.phone);
		
			fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d \n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.pancard, upd.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
			printf("\tChanges saved!");
			}
				else {
					printf("\t\tERROR!!! Enter valid Choice ");
					goto valid;
				}
			}
		else
			fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d \n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.pancard, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
		}
    
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");

	if(test!=1) {
		printf("\n\tRecord not found!!\a\a\a");
        
		edit_invalid:
		printf("\n\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&main_exit);
        
	if(main_exit==0) {
		system("clear");
		update();
	}
	else if (main_exit==1) {
		system("clear");
		main_menu();
	}
		else if (main_exit==2) {
			system("clear");
			close();
		}
			else {
				printf("\nInvalid!\a");
				system("clear");
				goto edit_invalid;
			}
	}
	else {
		printf("\n\n\n\tEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&main_exit);
		if (main_exit==1) {
			system("clear");
			main_menu();
		}
		else {
			system("clear");
			close();
		}
	}
}

	/* code for making transaction */
void transact(void) {   
	system("clear");
	int choice,test = 0;
	FILE *old, *newrec;
	old = fopen("record.dat","r");
	newrec = fopen("new.dat","w");

	printf("\n\n\tEnter the account no. of the customer:");
	scanf("%d", &transac.acc_no);
	while((fscanf(old,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.address, add.pancard, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year)) != EOF) {
		if(add.acc_no == transac.acc_no) {
			test = 1;
			if(strcasecmp(add.acc_type, "fixed1")==0||strcasecmp(add.acc_type, "fixed2")==0||strcasecmp(add.acc_type, "fixed3")==0) {
				printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!\n");
				main_menu();
			}
			wchoice:
			printf("\n\n\tDo you want to\n\t1.Deposit\n\t2.Withdraw?\n\n\tEnter your choice(1 for deposit and 2 for withdraw):");
			scanf("%d", &choice);
			
			if(choice == 1) {
				printf("\tEnter the amount you want to deposit:₹ ");
				scanf("%f", &transac.amt);
				add.amt += transac.amt;
				fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d \n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.pancard, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);        
				printf("\n\n\tDeposited successfully!");
			}
			else if(choice == 2){
				printf("\tEnter the amount you want to withdraw:₹ ");
				scanf("%f", &transac.amt);
				add.amt -= transac.amt;
				fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d \n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.pancard, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
				printf("\n\n\tWithdrawn successfully!");
			}
				else {
					printf("\n\n\tERROR!!! Enter the right choice\n");
					goto wchoice;
				}
		}
 		else {
			fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d \n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.pancard, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
		}
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");   
	if(test!=1) {
		printf("\n\n\tRecord not found!!");
		transact_invalid:
		printf("\n\n\n\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&main_exit);
		
		if (main_exit == 0) {
        	system("clear");
        	transact();
        	
        }
		else if (main_exit == 1) {
        	system("clear");
        	main_menu();
        	
        }
    		else if (main_exit == 2)
				close();
				else {
					system("clear");
					printf("\nInvalid!");
					goto transact_invalid;
				}

	}
	else {
		printf("\n\tEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d", &main_exit);
		if (main_exit == 1) {
			system("clear");
			main_menu();
		}
		else {
			system("clear");
			close();
		}
	}
}

		/*code to view account detail*/
void acc_report(void) {
	system("clear");
	FILE *fp;
	int test=0,rate;
	float time;
	float intrst;
	fp = fopen("record.dat","r");
    
	printf("\n\n\tEnter Your account number for account detail: ");
	scanf("%d", &check.acc_no);
    
	while(!feof(fp)) {
		fscanf(fp,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.address, add.pancard, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year);
		if(add.acc_no == check.acc_no) {
			test = 1;
			printf("\n\tAccount NO.:%d\n\tName:%s \n\tDOB:%d/%d/%d \n\tAge:%d \n\tAddress:%s \n\tPan Card No.:%s \n\tPhone number:%lld \n\tType Of Account:%s \n\tAmount deposited:₹ %.2f \n\tDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.pancard, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
			if(strcasecmp(add.acc_type,"fixed1") == 0) {
				time = 1.0;
				rate = 9;
				intrst = interest(time, add.amt, rate);
				printf("\n\tYou will get ₹%.2f as interest on %d/%d/%d\n", intrst, add.deposit.day, add.deposit.month, add.deposit.year+1);
				
			}
			else if(strcasecmp(add.acc_type,"fixed2") == 0) {
				time = 2.0;
				rate = 11;
				intrst = interest(time, add.amt, rate);
				printf("\n\tYou will get ₹.%.2f as interest on %d/%d/%d\n", intrst, add.deposit.day ,add.deposit.month, add.deposit.year+2);
				
			}
				else if(strcasecmp(add.acc_type,"fixed3") == 0) {
					time = 3.0;
					rate = 13;
					intrst = interest(time, add.amt, rate);
					printf("\n\tYou will get ₹.%.2f as interest on %d/%d/%d\n", intrst, add.deposit.day, add.deposit.month, add.deposit.year+3);
					
				}
					else if(strcasecmp(add.acc_type,"saving") == 0) {
						time = (1.0/12.0);
						rate = 8;
						intrst = interest(time,add.amt,rate);
						printf("\n\tYou will get ₹.%.2f as interest on %d of every month\n", intrst, add.deposit.day);
					}
						else if(strcasecmp(add.acc_type,"current")==0) {
							printf("\n\tYou will get no interest\a\a\n");
							
						}
		}
	}
	fclose(fp);
	if(test!=1) {
		printf("\n\tRecord not found!!\a\a\a");
		view_invalid:
		printf("\n\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&main_exit);

		if (main_exit == 1) {
			system("clear");
			main_menu();
			
		}
		else if (main_exit == 2) {
			system("clear");
			close();
			}
			else if(main_exit == 0) {
				system("clear");
				acc_report();
				
			}
			else {
					printf("\nInvalid!\a");
					system("clear");
					goto view_invalid;
					
				}
	}
	else {
		printf("\n\tEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&main_exit);
	}
		if (main_exit == 1) {
			system("clear");
			main_menu();
		}
		else {
			system("clear");
			close();
		}
}

	/* code to deleting existing account */	
void remv() {
	system("clear");
	FILE *old, *newrec;
	int test=0;
	old=fopen("record.dat","r");
	newrec=fopen("new.dat","w");
    
	printf("\n\n\tEnter the account no. of the customer you want to delete:");
	scanf("%d", &rem.acc_no);
	while((fscanf(old,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.address, add.pancard, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year)) != EOF ) {
		if(add.acc_no != rem.acc_no)
			fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d \n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.pancard, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
        	else {
        		test++;
        		printf("\n\tRecord deleted successfully!\n");
		}
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");
	
	if(test == 0) {
		printf("\n\tRecord not found!!\a\a\a");
		erase_invalid:
		printf("\n\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d", &main_exit);
	
		if(main_exit == 1) {
    			system("clear");
			main_menu();
		}
        	else if(main_exit == 2) {
			close();
			system("clear");
		}
			else if(main_exit == 0) {
				system("clear");
				remv();
			}
                	else {
				printf("\nInvalid!\a");
				system("clear");
				goto erase_invalid;}
	}
	else {
		printf("\n\tEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d", &main_exit);
	        if(main_exit == 1) {
			system("clear");
			main_menu();
		}
		else {
			system("clear");
			close();
		}
	}
}

void custm_list() {
	system("clear");
	FILE *view;
	view = fopen("record.dat","r");
	int test=0;
	printf("\n\tACC. NO.\t\tNAME\t\t\t\tADDRESS\t\t\t\tPHONE\n");

	while(!feof(view)) {
		fscanf(view,"%d %s %d/%d/%d %d %s %s %lld %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.address, add.pancard, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year);           		printf("\n\t%d\t\t%12s\t\t\t\t%10s\t\t\t%10lld",add.acc_no,add.name,add.address,add.phone);
		test++;
	}
	fclose(view);
	if(test == 0) {
		printf("\n\tNO RECORDS!!\n");
	}

	view_list_invalid:
	printf("\n\n\tEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	if(main_exit == 1) {
		system("clear");
		main_menu();
		
	}
		else if(main_exit==0) {
			system("clear");
			close();
		}
			else {
				printf("\nInvalid!\a");
				system("clear");
				goto view_list_invalid;
				
			}
}

	/* code for main mainu*/
void main_menu(void){
	system("clear");
	int choice;
	printf("\n\n\t\t\tCUSTOMER ACCOUNT BANK MANAGEMENT SYSTEM");
	printf("\n\n\n\t\t\t WELCOME TO THE MAIN MENU ");
	printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
	scanf("%d",&choice);

	switch(choice) {
		case 1:new_acc();
		break;
		case 2:update();
		break;
		case 3:transact();
		break;
		case 4:acc_report();
		break;
		case 5:remv();
		break;
		case 6:custm_list();
		break;
		case 7:close();
		break;
	}
}

int main() {
	system("clear");
	char pass[16], id[16];
	char password[16]="it", login[16] = "8017";
    	
    	/*Administration Login*/
	printf("\n\n\t\tEnter Your ID to login:");
	scanf("%s", id);
	printf("\n\n\t\tEnter the password:");
	scanf("%s", pass);
        
        /*Check for correct id and password*/
	if(strcmp(id, login) == 0 && strcmp(pass, password) == 0) {
		main_menu(); 
	}
	else if(strcmp(id, login) != 0 && strcmp(pass, password) != 0) {
		printf("\n\n\tWrong Login ID and Password!!\a\a\a");
		login_try:
		printf("\n\tEnter 1 to try again and 0 to exit:");
		scanf("%d",&main_exit);
		if(main_exit==1) {
			system("clear");
			main();
		}
		else if(main_exit==0) {
			system("clear");
			close();
		}
			else {
				printf("\nInvalid!");
				system("clear");
				goto login_try;
			}
	}
		else if(strcmp(id, login) != 0){
			printf("\n\n\tWrong Login ID!!\a\a\a");
			goto login_try;
		}
			else
				printf("\n\n\tWrong password!!\a\a\a");
				goto login_try;
	return 0;
}

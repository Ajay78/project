struct date {
	int month,day,year;
};
struct node {
	char name[16];
	int acc_no,age;
	char address[16];
	char pancard[16];
	long long phone;
	char acc_type[16];
	float amt;
	struct date dob;
	struct date deposit;
	struct date withdraw;
}add,upd,check,rem,transac;

void main_menu(void);      /*to create main menu*/
void new_acc();            /*to create new account*/
void acc_report(void);     /*to finding account detail*/
void update(void);           /*to edit acoount information*/
void transact(void);       /*For making transaction*/
void custm_list();         /*to display customer list*/
void remv(void);           /*for deleting costomer from data base*/
float interest(float time,float amount,int rate); /*for interest on ammount deposited*/

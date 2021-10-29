//Fauzan Harlyanto Putra
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//linked list buat data biasa
struct data{
	char menuName[101];
	char menuType[101];
	int menuQty;
	int menuPrice;
	
	//hands
	struct data *next;
	struct data *prev;
} *head = NULL, *tail = NULL;

//linkedlist buat data customer
struct dataCust{
	char menuNameCust[101];
	char menuTypeCust[101];
	int menuQtyCust;
	int menuPriceCust;
	
	//hands
	struct dataCust *nextCust;
	struct dataCust *prevCust;
} *headCust = NULL, *tailCust = NULL;


//push data biasa
void insert (char menuName[], char menuType[], int menuQty, int menuPrice){
	struct data *curr = (struct data *) malloc (sizeof(struct data));
	strcpy(curr->menuName, menuName);
	strcpy(curr->menuType, menuType);
	curr->menuQty = menuQty;
	curr->menuPrice = menuPrice;
	//hands
	curr->next = NULL;
	curr->prev = NULL;
	
	if (head == NULL){
		head = tail = curr;
	}
	else {
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
}

//push data customer
void insertCust (char menuNameCust[], char menuTypeCust[], int menuQtyCust, int menuPriceCust){
	struct dataCust *currCust = (struct dataCust *) malloc (sizeof(struct dataCust));
	strcpy(currCust->menuNameCust, menuNameCust);
	strcpy(currCust->menuTypeCust, menuTypeCust);
	currCust->menuQtyCust = menuQtyCust;
	currCust->menuPriceCust = menuPriceCust;
	//hands
	currCust->nextCust = NULL;
	currCust->prevCust = NULL;
	
	if (headCust == NULL){
		headCust = tailCust = currCust;
	}
	else {
		tailCust->nextCust = currCust;
		currCust->prevCust = tailCust;
		tailCust = currCust;
	}
}

//total quantity for admin
int totalQuantity(int menuNum){
	int num = 1;
	struct data *curr = head;
	if(head != NULL){
		if(menuNum == 1){
			return curr->menuQty;
		}
		else{
			while(curr != NULL && num != menuNum ){
				num++;
				curr = curr->next;
			}
			if(num == menuNum){
				return curr->menuQty;
			}
		}
	}
	else { //jika ga ada data
		puts("No Data Available");
	}
}

//total quantity for customer
int totalQuantityCust(int menuNum){
	int num = 1;
	struct dataCust *currCust = headCust;
	if(headCust != NULL){
		if(menuNum == 1){
			return currCust->menuQtyCust;
		}
		else{
			while(currCust != NULL && num != menuNum ){
				num++;
				currCust = currCust->nextCust;
			}
			if(num == menuNum){
				return currCust->menuQtyCust;
			}
		}
	}
	else { //jika ga ada data
		puts("No Data Available");
	}
}

//total price for admin
int totalPrice(int menuNum){
	int num = 1;
	struct data *curr = head;
	
	if (head != NULL){
		if(menuNum == 1){
			return curr->menuPrice;
		}
		else{
			while(curr != NULL && num != menuNum){
				num++;
				curr = curr->next;
			}
			if(num == menuNum){
				return curr->menuPrice;
			}
		}
	}
	else {//jika ga ada data
	 	puts("No Data Available");
	}
}

//total price for customer
int totalPriceCust(int menuNum){
	int num = 1;
	struct dataCust *currCust = headCust;
	
	if (headCust != NULL){
		if(menuNum == 1){
			return currCust->menuPriceCust;
		}
		else{
			while(currCust != NULL && num != menuNum){
				num++;
				currCust = currCust->nextCust;
			}
			if(num == menuNum){
				return currCust->menuPriceCust;
			}
		}
	}
	else {//jika ga ada data
	 	puts("No Data Available");
	}
}

//update quantity
void updateMenuQty(int menuNum, int newMenuQty){
	struct data *curr = head;
	int num = 1;
	
	while(curr != NULL && num != menuNum){
		num++;
		curr = curr->next;
	}
	if(num == menuNum){
		curr->menuQty= newMenuQty;
	}
}

//update order
void updateOrderCust(int menuNum, int newMenuQty, int newMenuPrice){
	struct dataCust *currCust = headCust;
	int num = 1;
	
	while(currCust != NULL && num != menuNum){
		currCust = currCust->nextCust;
		num++;
	}
	if(num == menuNum){
		currCust->menuQtyCust = newMenuQty;
		currCust->menuPriceCust = newMenuPrice;
	}
}

//function tersier
void capitalize(char nama[]){
	int length = strlen(nama);
	for (int i=0; i<length; i++){
		if ((nama[0] >= 'a') && (nama[0] <= 'z')){
			nama[0] = nama[0]-32;
		}
	}
}

int totalMenu(){
	int num = 0;
	struct data *curr = head;
	if (head != NULL){	
		while (curr){
			num++;
			curr = curr->next;
		}
	}
	return num;
}

//Admin Delete
void remove (int menuNum){
	struct data *curr = head;
	int num = 1;
	
	if (head != NULL){
		if (menuNum == 1){
			if (tail == curr){
			curr = head = tail = NULL;
			free(curr);
			}
			else{
			head = head->next;
			free(curr);
			head->prev = NULL;
			}
		}
		else if (menuNum == totalMenu()){
			curr = tail;
			if (head == curr){
				curr = head = tail = NULL;
				free(curr);
			}
			else {
				tail = tail -> prev;
				tail -> next = NULL;
				free(curr);
			}
		}	
		else {
			while (curr != NULL && num != menuNum ){	
				num++;
				curr = curr->next;
			}
			if (num == menuNum){
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
				curr->next = NULL;
				curr->prev = NULL;
				free(curr);
				curr = NULL;
			}
		}
	}
	else {//jika ga ada data
		printf("No Data Available\n");
	}
}

void removeCust(){
	struct dataCust *currCust = headCust;
	int num = 1;
	
	if (headCust != NULL){
		while (headCust != NULL){
			if (tailCust == currCust){
				currCust = headCust = tailCust = NULL;
				free(currCust);
			}
			else{
				headCust = headCust->nextCust;
				free(currCust);
				headCust->prevCust = NULL;
			}
		}
	}
	else {//jika ga ada data
		printf("No Data Available\n");
	}
}


int orderCheck(int menuNum){
	struct dataCust *currCust = headCust;
	char menuNameCust[101];
	
	
	if (currCust != NULL){
		while(currCust != NULL && strcmp(currCust->menuNameCust, menuNameCust) != 0){
			currCust = currCust->nextCust;
		}
		if(strcmp(currCust->menuNameCust, menuNameCust) == 0){
			return 0;
		}
		else{
			return 1;
		}
	}
	else {
		return 1;
	}
}


//header menu nya
void menuHeader(char *nama){
	puts("=============================================++=======================|");
	puts("                       ++Brew Coffee Shop++                           |");
	printf("Welcome. Mr./Mrs. %-52s|\n", nama);
	puts("                                                                      |");
	puts("============================++========================================|");
	puts("No.| Menu                     | Type        | Quantity | Price        |");
	puts(".......................................................................");
}

void orderHeader(){
	puts("Your order:");
	puts("============================++========================================|");
	puts("No.| Menu                     | Type        | Quantity | Price        |");
	puts(".......................................................................");
}

//tampilan menu 
void menuContent (){
	int num = 0;
	if (head != NULL){
		struct data *curr = head;
		while (curr){
			num++;
			capitalize(curr->menuName);
			if (strcmp(curr->menuType, "yes") == 0){
				printf("%-2d | %-24s |      Coffee | %8d | %12d |\n", num, curr->menuName, curr->menuQty, curr->menuPrice);
			}
			else if (strcmp(curr->menuType, "no") == 0){
				printf("%-2d | %-24s |  Non-Coffee | %8d | %12d |\n", num, curr->menuName, curr->menuQty, curr->menuPrice);
			} 
			
			curr = curr->next;
		}
	}
	else {//jika ga ada data
		printf("No Data Available\n");
	}
	puts(".......................................................................");
	
}

//tampilan order
void orderContent(){
	int num = 0;
	if (head != NULL){
		struct dataCust *currCust = headCust;
		while(currCust){
			num++;
			capitalize(currCust->menuNameCust);
			if (strcmp(currCust->menuTypeCust, "yes") == 0){
				printf("%-2d | %-24s |      Coffee | %8d | %12d |\n", num, currCust->menuNameCust, currCust->menuQtyCust, currCust->menuPriceCust);
			}
			else if (strcmp(currCust->menuTypeCust, "no") == 0){
				printf("%-2d | %-24s |  Non-Coffee | %8d | %12d |\n", num, currCust->menuNameCust, currCust->menuQtyCust, currCust->menuPriceCust);
			} 
			
			currCust = currCust->nextCust;
		}	
	}
	else {//jika ga ada data
		printf("No Data Available\n");
	}
	puts(".......................................................................");
}

void actionGuest(){
	puts("");
	puts("");
	puts("1. Buy Item");
	puts("2. Cancel Item");
	puts("3. Exit");
	puts("");
	puts("_____________________________________________________________________");
	printf("Enter your action: ");
}

void actionAdmin(){
	puts("1. Add Item");
	puts("2. Remove Item");
	puts("3. Exit");
	puts("");
	puts("_____________________________________________________________________");
	printf("Enter your action: ");
}


//menu untuk admin
void menuAdmin(int action){
	char menuName[101];
	char menuType[101];
	int menuQty;
	int menuPrice;
	int menuNum;
	switch(action){
		case 1 : //menu add
			do {
				printf("Insert item name: ");
				scanf("%s", menuName); getchar();
			}while (strlen(menuName) < 5 || strlen(menuName) > 20);
			
			do{
				printf("Type of Coffee [yes/no]: ");
				scanf("%s", menuType); getchar();
			}while((strcmp(menuType, "yes") != 0) && (strcmp(menuType, "no") != 0) );
			
					
			do {
				printf("Insert the quantity of the item: ");
				scanf("%d", &menuQty); getchar();
				}while (menuQty < 1 || menuQty > 100);
					
			do{
				printf("Insert the price of the item: ");
				scanf("%d", &menuPrice); getchar();
			}while(menuPrice < 10000 || menuPrice > 200000);
					
					
			insert (menuName, menuType, menuQty, menuPrice);
					
			break;
		case 2:		//menu remove
			if (totalMenu() != 0){
				do{
					printf("Choose your menu [1-%d]: ", totalMenu()); 
					scanf("%d", &menuNum); getchar();
					remove(menuNum);
				}while (menuNum < 1 || menuNum > totalMenu());
			}
			else {
				puts ("No Data Available");
			}
			break;
		case 3:		//menu exit
			puts("Thank you for visiting admin");
			break;
		default:	//menu error
			puts("input error, try again");
			break;
	}
}

//menu untuk guest
void menuGuest(int action){
	int menuNumCust;
	char menuNameCust[101];
	int menuQtyCust;	
	int set_totalQtyCust;
	int new_set_totalQtyCust;
	int set_totalPriceCust;
	int check;
	
	
	switch(action){
		case 1 : 	//menu buy
		
		
			do{
				printf("Choose your menu [1-%d]: ", totalMenu());
				scanf("%d", &menuNumCust);getchar();
			}while (menuNumCust < 1 || menuNumCust > totalMenu());
			
			set_totalQtyCust = totalQuantity(menuNumCust);
			
			
			if(set_totalQtyCust != 0){
				do{
					printf("Enter the quantity [1 - %d]: ", set_totalQtyCust);
					scanf("%d", &menuQtyCust); getchar();
				}while (menuQtyCust < 1 || menuQtyCust > set_totalQtyCust);
				
				set_totalPriceCust = totalPrice(menuNumCust);
				
				check = orderCheck(menuNumCust);
				
				if (check == 1){
					if(menuNumCust == 1) insertCust ("Americano", "yes", menuQtyCust, menuQtyCust * set_totalPriceCust);
					else if(menuNumCust == 2) insertCust ("Chocolate Baked", "no", menuQtyCust, menuQtyCust * set_totalPriceCust);
					else if(menuNumCust == 3) insertCust ("Alberto", "yes",menuQtyCust, menuQtyCust * set_totalPriceCust);
				}
				
				else if (check == 0){
					printf("Data Already exist\n");
					int currMenuPrice = totalPriceCust(menuNumCust);
					int newMenuPrice = currMenuPrice + (menuQtyCust * set_totalPriceCust);
					
					int currMenuQty = totalQuantityCust(menuNumCust);
					int newMenuQty = currMenuQty + menuQtyCust;
					
					updateOrderCust(menuNumCust, newMenuQty, newMenuPrice);
				}
				
				
				new_set_totalQtyCust = set_totalQtyCust - menuQtyCust;
				updateMenuQty(menuNumCust, new_set_totalQtyCust);
				printf("Success\n");
			}
			
			orderHeader();
			orderContent();
			
			break;
		case 2:
			updateMenuQty(1, 24);
			updateMenuQty(2, 15);
			updateMenuQty(3, 7);		
			removeCust();
			
			break;
		case 3:
			puts("Thank you for visiting");
			break;
		default:
			puts("input error, try again");
			break;
			}
}

//main function dudes
int main (){
	int action;
	char nama[101];
	printf("enter your name: ");
	scanf("%s", nama); getchar();
	capitalize(nama);	
	
	insert ("Americano", "yes", 24, 19000);
	insert ("Chocolate Baked", "no", 15, 24000);
	insert ("Alberto", "yes", 7, 44000);
		
		do{
			puts("");
			puts("");
			menuHeader(nama);
			menuContent();
			if (strcmp(nama, "Admin")==0){
				actionAdmin();
				scanf("%d", &action);
				menuAdmin(action);
			}
			else {
				actionGuest();
				scanf("%d", &action);
				menuGuest(action);
			}
			
		}while(action != 3);
	
	printf("program ended");
	return 0;
}

//Kushal Kharel 
//Lab 10
//Bitmap
#include <stdio.h>
#include <stdlib.h>

//global mem bitmap of 128 KB
//2 dimensional array could also work 
//this is our memory all initilized to 0 in the beganning 
int Bitmap[64] = {
    1,0,0,0,0,1,0,0,
    0,0,1,0,0,1,1,1,
    0,1,0,0,0,0,0,0,
    0,0,1,1,1,0,0,0,
    0,0,0,0,1,0,0,0,
    1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,
    0,0,1,1,1,0,0,0
};

//resets the memory
void Reset(){
  for(int i = 0; i < 64; i++){
    Bitmap[i] = 0; 
  }
  printf("the current status of bit map:"); 
 int j; 
      printf("\n");
    for(j = 0; j < 64; j++){
        printf("%d", Bitmap[j]);
        if(j == 7 || j == 15 || j == 23 || j == 31 || j == 39 || j == 47 || j == 55 || j == 63) printf("\n");  
        //if(j == 63) exit(1); 
    }
}

int Mallocate(int req){

  //takes the requested space and returns the address of free block
  //or returns -1 if there are no free blocks 

  int space = req/2; //2 kb unit size. 
  int counter = 0; 
  int retVal ; 
  int mask[space]; 
  int comp[space]; 
  int temp[space]; 
  for(int i = 0; i < space; i++){
    mask[i] = 1; // mask is set all to 1s 
  }

 

  for(int i = 0; i < 64; i++){

    if(Bitmap[i] == 0){
      for(int j = 0; j < space; j++){
        comp[j] = Bitmap[i+j]; //gets the spaces from 0
      }
      //this is where you compare 
      

      for(int h = 0; h < space; h++){ //Bitwise comparison with mask (XOR)
        temp[h] = (comp[h] ^ mask[h]); 

      }

      
      int flag = 1; 

      for(int t = 0; t < space; t++){
        if(temp[t] == 0){
          flag = 0; //does not work 
        
         }
      }

      if(flag == 1){ //if the space works sets the return value 
        
        
        retVal = i; 
        break; //break out of loop
      }


      //exit(1);
    }

  }
  return retVal; 
}

void Free(int Address, int Size){
  //takes address and size from the user and reset bits associated with this
  //address
  
  if(Address > 128 || Size > 128){
     
     printf("Error, the address or size exceeds the Memory bounds\n");
  }else{

      printf("Configuring the Memory\n");
     //---------change the bit map here------

     int ch = Size/2 ;  //this is the amount of bits to alter
     int ad = Address/2; //this is the address

     for(int i = ad; i < ch + ad; i++){

       Bitmap[i] = 1; 

     }
     //---------changing bitmap above--------
     printf("the current status of bit map:"); 

         printf("\n");
         int j; 
       for(j = 0; j < 64; j++){
        printf("%d", Bitmap[j]);
        if(j == 7 || j == 15 || j == 23 || j == 31 || j == 39 || j == 47 || j == 55 || j == 63) printf("\n");  
        //if(j == 63) exit(1); 
    }
         
       }
}

int main(void) {

  //this is the very beganing of the program
  printf("the current status of bit map:"); 
 int j; 
      printf("\n");
    for(j = 0; j < 64; j++){
        printf("%d", Bitmap[j]);
        if(j == 7 || j == 15 || j == 23 || j == 31 || j == 39 || j == 47 || j == 55 || j == 63) { printf(" (0x%d)\n", j*2+2); } 
      
    }
    
  int num; //this is the counter for loop (will always run)
  int UserChoice; 
    printf("----------------------------Menu--------------------------------");
      printf("\nWould you like to configure the Map or search for space\n"); 
      printf("1 = Configure the map\n"); 
      printf("2 = search for free memory\n");
      printf("3 = Reset Memory\n");
      printf("4 = Exit program\n"); 
       //scanf("%d", &UserChoice);

    scanf("%d", &UserChoice);

    if(UserChoice == 4){ exit(0);}
  while(num != 4){
    if(UserChoice == 4){
      exit(0);
    }
    if(UserChoice == 1){
      //here we configure the map 
      //call the funciton free
      //printf(); 
      int address, size; 
      printf("Configuring the map\n");
      printf("Enter the Address: "); 
      scanf("%d", &address);
     // printf("\n");
      printf("Enter Size in KB: ");  
      scanf("%d", &size); 

      Free(address, size); 
     printf("----------------------------Menu--------------------------------");
     printf("\nWould you like to configure the Map or search for space\n"); 
      printf("1 = Configure the map\n"); 
      printf("2 = search for free memory\n");
      printf("3 = Reset Memory\n");
      printf("4 = Exit program\n"); 
       scanf("%d", &UserChoice);
    }else if(UserChoice == 2){
      

      //call the finder funciton 
      printf("\nEnter requested size in KB\n");
      int ReqSize; 
      scanf("%d", &ReqSize);
      printf("searching for free space\n");
      
      int addFree = Mallocate(ReqSize); 

      printf("Free space for process is at address: %d\n",2* addFree); 
     printf("----------------------------Menu--------------------------------"); 
     printf("\nWould you like to configure the Map or search for space\n"); 
      printf("1 = Configure the map\n"); 
      printf("2 = search for free memory\n");
      printf("3 = Reset Memory\n");
      printf("4 = Exit program\n"); 
       scanf("%d", &UserChoice);
      //in here we work to search the map
      //call the function mallocate 
    }else if(UserChoice ==3){

      Reset(); 
      printf("----------------------------Menu--------------------------------");
      printf("\nWould you like to configure the Map or search for space\n"); 
      printf("1 = Configure the map\n"); 
      printf("2 = search for free memory\n");
      printf("3 = Reset Memory\n");
      printf("4 = Exit program\n"); 
       scanf("%d", &UserChoice);
     // num = 0; 
      //exit just the loop 
    }else if(UserChoice == 4){
      exit(0);
    }
    
    else{
      printf("Error"); 
    printf("----------------------------Menu--------------------------------");
     printf("\nWould you like to configure the Map or search for space\n"); 
      printf("1 = Configure the map\n"); 
      printf("2 = search for free memory\n");
      printf("3 = Reset Memory\n");
      printf("4 = Exit program\n"); 
       scanf("%d", &UserChoice);
      
    }
  }
  return 0;
}
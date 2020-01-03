#include<stdio.h>
#include<iostream>
#include <iomanip>
#include <stdlib.h>
#include<string>
#include <sstream> 
#include<math.h>
#include<time.h>

using namespace std;

string add(string a, string b){//addition operation
	string temp="";
	int size1 = a.size(); 
    int size2 = b.size();
    int max_size=0;
    int carry=0;
    if (size1>=size2){  //write zeros to the beginning of the binary number if its size is lesser than the other binary number
    	max_size=size1;
    	for(int i=0;i<size1-size2;i++)
    		b='0'+b;
	}    	
    else{
    	max_size=size2;
		for(int i=0;i<size2-size1;i++)
    		a='0'+a;
	} 
	
	for(int i=max_size-1;i>=0;i--){     //binary addition with carry formulas are utilized here
		if((a[i]=='0')&&(b[i]=='0')){	
			if(carry==0)
				temp='0'+temp;
			else{
				temp='1'+temp;
				carry=0;				
			}
		}			
		else if (((a[i]=='0')&&(b[i]=='1'))||((a[i]=='1')&&(b[i]=='0'))){
			if(carry==0)
				temp='1'+temp;
			else{
				temp='0'+temp;
				carry=1;				
			}
		}
		else if((a[i]=='1')&&(b[i]=='1')){	
			if(carry==0)		
				temp='0'+temp;							
			else
				temp='1'+temp;
			carry=1;							
		}				
	}
	if(carry==1){
		temp='1'+temp;
		carry=0;
	}
return temp;
}



int shift_add(string a, string b){//multiplication by shifting and adding
	int size1 = a.size(); 
    int size2 = b.size();
    string result[1000]="";
    string temp2[1000]="";
    string temp[1000]="";
    
    int occurence_of_digit=0;
	long long int in_decimal=0;
	int index=0;
	
	for(int i=size2-1;i>=0;i--){
		occurence_of_digit+=1;
		if(b[i]=='0'){	//since multiplication of 0 with any number is zero, fill the string with as many 0s as the size of the multiplicant
			for(int j=0;j<size1;j++)
				result[i]+='0';
			for(int l=0;l<occurence_of_digit-1;l++)//shifting operation
				result[i]+='0';
		}		
		else if(b[i]=='1'){	//since multiplication of 1 with any number is the number, copy the multiplicant to the string
			for(int k=0;k<size1;k++)
				result[i]+=a[k];
			for(int l=0;l<occurence_of_digit-1;l++)
				result[i]+='0';				
		}		
	}
	
	for(int i=size2-1;i>=0;i--){//store the result of ith addition in (i+1)th index add operation
		temp[i-size2-2]=add(temp[i-size2-1],result[i]);			
	}
	//cout<<"result of multiplication with shift_add method in binary: "<<temp[-size2-2]<<endl;
	
	int size_result = temp[0-size2-2].size(); //size of the result		
	for(int i=0;i<size_result;i++){
		index=temp[-size2-2][i]- '0';//get integer version
		in_decimal+=index*pow(2,size_result-i-1);//convert to decimal

	}
return in_decimal;
}

long long int multiply(string a, string b){//karatsuba
	string xl="";
    string xr="";     	
   	string yl="";
   	string yr="";
   	
	int size1 = int(a.size()); 
    int size2 = int(b.size());
    int max_size;
         	
   	long long int p1;
    long long int p2;
    long long int p3;
    
    if (size1>=size2){   //write zeros to the beginning of the binary number if its size is lesser than the other binary number
    	max_size=size1;
    	for(int i=0;i<size1-size2;i++)
    		b='0'+b;
	}    	
    else{
    	max_size=size2;
		for(int i=0;i<size2-size1;i++)
    		a='0'+a;
	} 
	
	int first_half=max_size/2;
    int second_half=max_size-max_size/2;

    if (max_size==1)//a*b
    	return (a[0] - '0')*(b[0] - '0');
       	
     	for(int i=0;i<first_half;i++)//copying leftmost bits of a into xl
     		xl+=a[i];
     		
		for(int i=first_half;i<max_size;i++)////copying rightmost bits of a into xl
			xr+=a[i];
					
		for(int i=0;i<first_half;i++)
			yl+=b[i];
			
		for(int i=first_half;i<max_size;i++)
			yr+=b[i];

     	
     	
     	p1 = multiply(xl, yl);        
		p2 = multiply(xr, yr);
		p3 = multiply(add(xl,xr),add(yl,yr));
    	

return (p1*(pow(2,2*(max_size-max_size/2))) + (p3 - p1 - p2)*(pow(2,(max_size-max_size/2)))+ p2); 

}

int main() 
{   
    int max_value=16;//number of digits in each number
	srand(time(NULL)); 		
	ostringstream rand1;
	ostringstream rand2;
	string num1 = ""; 
	string num2 = ""; 
	
	//generating 2 random binary strings 
	for(int i=0;i<max_value;i++){

    	rand1 << (rand() % 2); 
   		rand2 << (rand() % 2); 
		num1 = rand1.str(); 
		num2 = rand2.str();
	 
    }

    cout<<"size of the inputs: "<<max_value<<endl;
    cout << "the inputs are : "<<num1<< " "<<num2<< endl; 

  	double t1=clock();
  	cout<<"result of multiplication with shift add method in decimal: "<< shift_add(num1,num2)<<endl;
  	double t2=clock();
  	std::cout << std::fixed << "passed time by utilizing shift add: " << std::setprecision(5) << (t2 - t1)<< std::endl;
 
	double t3=clock();
  	cout<<"result of multiplication with karatsuba method in decimal: "<< multiply(num1,num2)<<endl;
  	double t4=clock();
  	std::cout << std::fixed << "passed time by utilizing karatsuba: " << std::setprecision(5) << (t4 - t3)<< std::endl;
 
    return 0; 
} 

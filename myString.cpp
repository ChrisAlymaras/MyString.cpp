#include <iostream>

using namespace std;

class myString{
	private:
		char* data; //character array to store the string
		int length; //hold the length of the string
	public:
		myString(); //empty string constructor
		myString(const char*); //given string constructor
		myString(const myString&); //copy constructor
		int get_length(); //getter for string length
		const char* get_data(); //getter for string data
		void operator+=(char); //add character at the end of the string
		bool operator==(const myString&); //check if strings are equal
		bool operator!=(const myString&); //check if strings are not equal
		bool operator>(const myString&); //check if string is bigger than another
		bool operator<(const myString&); //check if string is smaller than another
};


//empty string constructor
myString::myString(){
	data=new char[1];
	length=0;
	data[0]='\0';
}

//given string constructor
myString::myString(const char* str){
	length=0;
	while(str[length]!='\0'){
		++length;
	}
	data=new char[length+1];
	for (int i=0; i<length; i++){
		data[i]=str[i];
	}
	data[length]='\0';
}

//copy constructor
myString::myString(const myString& copy){
	length=copy.length;
	data=new char[length+1];
	for (int i=0; i<length; i++){
		data[i]=copy.data[i];
	}
	data[length]='\0';
}

//return string
const char* myString::get_data(){
	return data;
} 

//get string length
int myString::get_length(){
	return length;
}

//overload += operator to add a character in the end of the string
void myString::operator+=(char ch){    
	length+=1;
	char* tempData=new char[length+1];
	for (int i=0; i<length-1; i++){
		tempData[i]=data[i];
	}
	tempData[length-1]=ch;
	tempData[length]='\0';
	//overwrite original data
	data=new char[length+1];
	for (int i=0; i<length; i++){
		data[i]=tempData[i];
	}
	delete[] tempData;	
}

//overload operator == to check if strings are equal
bool myString::operator==(const myString& str){
        if (length != str.length){
            return false;
        }
        for (int i = 0; i < length; i++) {
            if (data[i] != str.data[i]){
            	return false;
            }
        }
        return true;
}

//overload operator != to check if strings are not equal
bool myString::operator!=(const myString& str){
	if (length != str.length){
            return true;
        }
        for (int i = 0; i < length; i++) {
            if (data[i] != str.data[i]){
            	return true;
            }
        }
        return false;
}

//overload operator < to check if string is smaller than another
bool myString::operator<(const myString& str){
	if (length < str.length){
            return true;
        }
        return false;
}

//overload operator > to check if string is bigger than another 
bool myString::operator>(const myString& str){
	if (length > str.length){
            return true;
        }
        return false;
}


int main(int argc,char **argv){
	//create a string
	myString str("hello");
	//add to existed string some other characters
	str+=' ';
	str+='B';
	str+='r';
	str+='o';
	//print full string
	cout<<"String: "<<str.get_data()<<endl;
	cout<<"String length: "<<str.get_length()<<endl;
	cout<<endl;
	
	//create other strings
	myString str2("hello Bro");
	cout<<"String: "<<str2.get_data()<<endl;
	cout<<"String length: "<<str2.get_length()<<endl;
	cout<<endl;
	
	myString str3("Good Morning");
	cout<<"String: "<<str3.get_data()<<endl;
	cout<<"String length: "<<str3.get_length()<<endl;
	cout<<endl;
	
	//compare str and str2
	if (str==str2){
		cout<<"Strings str and str2 are equal"<<endl;
	}else if(str!=str2){
		cout<<"Strings str and str2 are not equal"<<endl;
	}
	
	//compare str2 and str3
	if (str2!=str3){
		cout<<"Strings str2 and str3 are not equal"<<endl;
		if (str2<str3){cout<<"Str2 is smaller"<<endl;}
		if (str2>str3){cout<<"Str2 is bigger"<<endl;}
	}
	
	return 0;
}
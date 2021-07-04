#include<iostream>
#include<vector>
using namespace std;
int main()
{
	string numberString2; 
	string numberString1;
	string tempString;
	cin>>numberString2;
	cin>>numberString1;

	int sizeDifference = numberString2.size() - numberString1.size();
	
	bool isNegative = false;

	if(sizeDifference < 0 ) {
		swap(numberString2,numberString1);
		sizeDifference *= -1;
		isNegative = true;
	}
	else if(sizeDifference == 0){
			
			int i = 0;

			while(numberString2[i] == numberString1[i]){
				i++;
			}

			if(numberString2[i] < numberString1[i]){

				swap(numberString2,numberString1);
				sizeDifference *= -1;
				isNegative = true;
			}
	}

	vector<char> result(numberString2.size());

	int i;

	for(i = numberString2.size()-1; i>= sizeDifference ; i--){

		int diff = numberString2[i] - numberString1[i - sizeDifference];

		if(diff<0){
			diff += 10;
			numberString2[i-1] -= 1; 
		}

		result[i] = diff + '0';
	}

	for(i = sizeDifference - 1; i>=0; i--){
		result[i] = numberString2[i];
	}


	if(isNegative == true){
		cout<<"-";
	}

	int j=0;
	
	while(result[j] == '0'){
		j++;
	}
	
	if(j == result.size()){
		cout<<0;
	}

	for(j = j; j<result.size(); j++){
		cout<<result[j];
	}

}
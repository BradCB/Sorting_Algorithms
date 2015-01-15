#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<fstream>


//-----------sorting protos--------------//

void sort(std::vector<int> &);
void bubblesort(std::vector<int> &,int);
void selectionSort(std::vector<int> &);
void insertionSort(std::vector<int> &, int n);

void mergeSort(std::vector<int> &);
void mergeS(std::vector<int> &, std::vector<int>&, int, int);
void merge(std::vector<int> &, std::vector<int>&, int, int, int);



void swap(std::vector<int>& vec, int start, int end);
int partition(std::vector<int>&vec, int start, int end);
void quickSort(std::vector<int>&vec, int start, int end);

void printFile( char,int , float );
void displayvector(std::vector<int> value);

int main()
{
	int size = 0;
	char method;

	std::cout<<"Please enter the size of the array to test: ";
	std::cin>>size;

	std::vector<int> a(size);

	std::generate(a.begin(), a.end(), []{return rand();});

	std::clock_t duration;
	
//---------------------------------------sort funtion--------------------------//

	std::cout<<"\n-----------RUNNING SORT ALGORITHM-------------"<<std::endl;
	std::cout<<"-----------UNSORTED----------"<<std::endl;
	displayvector(a);
	duration = clock();
	{
		sort(a);
	}
	
	std::cout<<"-----------SORTED----------"<<std::endl;
	duration = clock()-duration;
	displayvector(a);
	std::cout<<"\n Sort algorithm Time array size clock ticks: "<<(((float)duration)/CLOCKS_PER_SEC)<<std::endl;
	method = 'S';
	printFile(method,size , duration );



	
//---------------------------------------bubble sort funtion--------------------------//

	std::generate(a.begin(), a.end(), []{return rand();});
	std::cout<<"-----------UNSORTED----------"<<std::endl;
	displayvector(a);
	std::cout<<"\n-----------RUNNING BUBBLE SORT ALGORITHM-------------"<<std::endl;
	duration = clock();
	{

		bubblesort(a,a.size());
	}
	duration = clock()-duration;
	std::cout<<"-----------SORTED----------"<<std::endl;
	displayvector(a);

	std::cout<<"\n Bubble Sort algorithm Time array size clock ticks: "<<(((float)duration)/CLOCKS_PER_SEC)<<std::endl;
	method = 'b';
	printFile(method,size , duration );
	

//---------------------------------------selection sort funtion--------------------------//

	std::cout<<"\n-----------RUNNING SELECTION SORT ALGORITHM-------------"<<std::endl;
	std::generate(a.begin(), a.end(), []{return rand();});
	std::cout<<"-----------UNSORTED----------"<<std::endl;
	displayvector(a);
	duration = clock();
	{

		selectionSort(a);
	}
	duration = clock()-duration;
	std::cout<<"-----------SORTED----------"<<std::endl;
	displayvector(a);

	std::cout<<"\n Selection Sort algorithm Time array clock ticks: "<<(((float)duration)/CLOCKS_PER_SEC)<<std::endl;
	method = 's';
	printFile(method,size , duration );


//---------------------------------------insertion sort funtion--------------------------//
	
	std::cout<<"\n-----------insertion SELECTION SORT ALGORITHM-------------"<<std::endl;
	std::generate(a.begin(), a.end(), []{return rand();});
	std::cout<<"a unstorted: "<<std::endl;
	displayvector(a);
	duration = clock();
	{

		insertionSort(a, a.size());
	}
	duration = clock()-duration;
	std::cout<<"-----------SORTED----------"<<std::endl;
	displayvector(a);
	std::cout<<"\n Insertion Sort algorithm Time clock ticks: "<<(((float)duration)/CLOCKS_PER_SEC)<<std::endl;
	method = 'i';
	printFile(method,size , duration );


//---------------------------------------Merge sort funtion--------------------------//
	
	std::cout<<"\n-----------MERGE SORT ALGORITHM-------------"<<std::endl;
	std::generate(a.begin(), a.end(), []{return rand();});
	std::cout<<"a unstorted: "<<std::endl;
	displayvector(a);
	duration = clock();
	{

		mergeSort(a);
	}
	duration = clock()-duration;
	std::cout<<"-----------SORTED----------"<<std::endl;
	displayvector(a);
	std::cout<<"\n Merge Sort algorithm Time clock ticks: "<<(((float)duration)/CLOCKS_PER_SEC)<<std::endl;
	method = 'm';
	printFile(method,size , duration );

//---------------------------------------Quick sort funtion--------------------------//
	
	std::cout<<"\n-----------QUICK SORT ALGORITHM-------------"<<std::endl;	

	std::generate(a.begin(), a.end(), []{return rand();});
	std::cout<<"a unstorted: "<<std::endl;
	displayvector(a);
	duration = clock();
	{

		quickSort(a, 0, a.size()-1);
	}
	duration = clock()-duration;
	std::cout<<"-----------SORTED----------"<<std::endl;
	displayvector(a);
	std::cout<<"\n Quick Sort algorithm Time clock ticks: "<<(((float)duration)/CLOCKS_PER_SEC)<<std::endl;
	method = 'q';
	printFile(method,size , duration );



}//--------------------------//end main


void displayvector(std::vector<int> value){

	for (unsigned count = 0; count < value.size(); count++)
			std::cout << count << ": "<< value[count] << std::endl;
			
}



/********************************************	
*											*
*		      STD sort						*
*				Function					*         
*											*
********************************************/

void sort(std::vector<int> &a){
	

	std::sort(a.begin(), a.end());
	
}


/********************************************	
*											*
*		      Inserton sort					*
*				Function					*         
*											*
********************************************/
void insertionSort(std::vector<int> &vec, int size){
	
	int i, j, temp;
	for(i = 1; i < vec.size(); ++i){

		temp = vec[i];
		j = i - 1;
		while( j >= 0 && vec[j] > temp){
			vec[j + 1] = vec[j];
			j = j-1;
		}
		vec[j+1] = temp;

		}

}


void printFile(char method, int a, float b){
	
	
	std::ofstream file;
	
	file.open("file.txt", std::ios::out|std::ios::app);
	file <<method<<": "<<a<<","<<(b)<<std::endl;
	file.close();

}

/********************************************	
*											*
*		      Bubble sort					*
*				Function					*         
*											*
********************************************/

void bubblesort(std::vector<int>& vec, int size)
{
	int temp;
	bool swap;
	do{ 
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (vec[count] > vec[count + 1])
			{
				temp = vec[count];
				vec[count] = vec[count + 1];
				vec[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}		
	



/********************************************	
*											*
*		      Selection sort				*
*				Function					*         
*											*
********************************************/
void selectionSort(std::vector<int> &a){
	

	int startScan, minIndex, minValue;

	for(startScan = 0; startScan< (a.size()-1); ++startScan)
	{
		minIndex = startScan;
		minValue = a[startScan];
		for(int i = startScan +1; i < a.size(); ++i)
		{
			if(a[i] < minValue)
			{
				minValue = a[i];
				minIndex = i;
			}
		}
		a[minIndex] = a[startScan];
		a[startScan] = minValue;
	}

	

}
/********************************************	
*											*
*		      Merge sort					*
*				Function					*         
*											*
********************************************/
void mergeSort(std::vector<int> & vec){

	std::vector<int>copy(vec.size());
	mergeS(vec, copy, 0, vec.size()-1);
	

}
void mergeS(std::vector <int>& vec, std::vector <int>&copy, int low, int high){

	if(low<high)
	{
		int mid = (low + high)/2;
		mergeS(vec, copy, low, mid);
		mergeS(vec, copy, mid +1, high);
		merge(vec, copy, low, mid, high);
	}
}
void merge(std::vector<int> &vec, std::vector<int>&copy, int low, int mid, int high){

	int i1 = low;
	int i2 = mid+1;
	int i;
	for(i=low;i<=high;++i)
	{
		if(i1> mid)
		copy[i] = vec[i2++];
		else if(i2 > high)
			copy[i] = vec[i1++];
		else if(vec[i1]<vec[i2])
			copy[i] = vec[i1++];
		else
			copy[i] = vec[i2++];
	}
	for(i = low; i<=high;++i){
		vec[i] = copy[i];

	}

	}
/********************************************	
*											*
*		      Quick sort					*
*				Function					*         
*											*
********************************************/
void swap(std::vector<int>& vec, int start, int end){

	 int temp = vec[start];
	 vec[start] = vec[end];
	 vec[end] = temp;
 }

int partition(std::vector<int>&vec, int start, int end){

	int part = start;
	for(int i = part+1; i<=end; ++i){

		if(vec[i] < vec[part])
		{
			swap(vec, i, part);
			if(i != part+1)
			{
				swap(vec, i, part+1);}
			part = part+1;

		}

	}
	return part;
}

void quickSort(std::vector<int>& vec, int start, int end){

	if(start >=end) return;
	int part = partition(vec, start, end);

	quickSort(vec, start, part-1);
	quickSort(vec, part+1, end);


}
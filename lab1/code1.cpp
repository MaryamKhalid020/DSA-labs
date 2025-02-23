//EXAMPLE 1.1
/*#include<iostream>
int max1(int X, int Y) {
	return(X > Y) ? X : Y;
}
void max2(int X, int Y, int& larger) {
	larger= (X > Y) ? X : Y;
}
void max3(int X, int Y, int *larger) {
	*larger = (X > Y) ? X : Y;
}*/


//EXAMPLE 1.2
/*#include<istream>
#include<math.h>
using namespace std;
class Complex {
private:
	float re;
	float img;
public:
	Complex(float r, float i) {
		re = r; img = i;
	}
	Complex(float r) {
		re = r; img = 0.0;
	}
	~Complex() {};

	double Magnitude() {
		return sqrt(re * re + Img() * Img());
	}
	float Real() { return re; }
	float Img() { return img; }
	Complex operator+(Complex b) {
		return Complex(re + b.re, img + b.img);
	}
	Complex operator=(Complex b) {
		return Complex(re = b.re, img = b.img);
	};

};
int main() {
	Complex a(1.0, 1.0);
	Complex* b = new Complex(5.0);
	Complex c(0, 0);
	cout << "a real =" << a.Real() << " a imaginary =" << a.Img();
	cout << "b real =" << b->Real() << " b imaginary =" << a.Img();
	c = a +(* b);
	cout << "c real = " << c.Real() << "c imaginary =" << c.Img();
	delete b;
	return 0;
}*/


//EXAMPLE 1.3
/*#include<iostream>
using namespace std;
template <class T>
T Getmax(T a, T b) {
	T result = (a > b) ? a : b;
	return(result);
}
int main() {
	int i = 5, j = 6, k;
	long l = 10, m = 5, n;
	k = Getmax<int>(i, j);
	n= Getmax<long>(l, m);
	cout << k << endl;
	cout << n << endl;
	return 0;
}*/


//EXAMPLE 1.4
/*#include <iostream>
using namespace std;

template <class T>
class mypair
{
    T a, b;
public:
    mypair(T first, T second)
    {
        a = first;
        b = second;
    }

    T getmax();
};

template <class T>
T mypair<T>::getmax()
{
    T retval;
    retval = a > b ? a : b;
    return retval;
}

int main()
{
    mypair<int> myobject(100, 75);
    cout << myobject.getmax();
    return 0;
}*/


//EXAMPLE 1.5
/* #include <iostream>
using namespace std;

template <class T, int N>
class mysequence
{
    T memblock[N];
public:
    void setmember(int x, T value);
    T getmember(int x);
    T getmax();
    T getmin();
};

template <class T, int N>
void mysequence<T, N>::setmember(int x, T value)
{
    memblock[x] = value;
}

template <class T, int N>
T mysequence<T, N>::getmember(int x)
{
    return memblock[x];
}

template <class T, int N>
T mysequence<T, N>::getmax()
{
    T max = memblock[0];
    for (int i = 1; i < N; i++)
    {
        if (memblock[i] > max)
        max = memblock[i];
    }
    return max;
}

template <class T,int N>
T mysequence<T, N>::getmin()
{
    T min = memblock[0];
    for (int i = 1; i < N; i++)
    {
        if (memblock[i] < min)
        min = memblock[i];
    }
    return min;
}
int main()
{
    mysequence<int, 4> myints;
    mysequence<double, 3> myfloats;

    myints.setmember(0, 100);
    myints.setmember(1, 23);
    myints.setmember(2, 758);
    myints.setmember(3, 22);

    myfloats.setmember(2, 3.1416);
    myfloats.setmember(1, 333);
    myfloats.setmember(0, 3);

    cout << myints.getmax() << '\n';
    cout << myfloats.getmin() << '\n';

    return 0;
}*/


//EXAMPLE 1.6:
/* #include <iostream>
#include <fstream>

    using namespace std;

int main(void)
{
    ofstream outFile;
    outFile.open("fout.txt");

    ifstream inFile("fin.txt");

    char ch;
    int count = 0;

    while (inFile.get(ch))
    {
        outFile << ch;
        count++;
    }
    outFile << "\n\n Character count = " << count << endl;

    inFile.close();
    outFile.close();

    return 0;
}*/

//EXAMPLE:1.7:
/*#include <iostream>
#include <fstream>

    using namespace std;

int main()
{
    char name[10];
    float mt1, mt2, final, avg;

    ifstream fin;       // Create file input stream object
    ofstream fout;      // Create file output stream object

    fin.open("input.dat");   // Open input file
    fout.open("output.dat"); // Open output file

    while (!fin.eof())       // Read data from input file
    {
        fin >> name >> mt1 >> mt2 >> final;
        avg = 0.25 * mt1 + 0.25 * mt2 + 0.5 * final;
        fout << name << '\t' << avg << endl;
        // Write result to output file
    }

    fin.close();   // Close input file
    fout.close();  // Close output file
}*/


//EXERCISES
//Exercise 1.1:
/*#include<istream>
#include<math.h>
using namespace std;
class Complex {
private:
	float re;
	float img;
public:
	Complex(float r, float i) {
		re = r; img = i;
	}
	Complex(float r) {
		re = r; img = 0.0;
	}
	~Complex() {};

	double Magnitude() {
		return sqrt(re * re + Img() * Img());
	}
	float Real() { return re; }
	float Img() { return img; }
	Complex operator+(Complex b) {
		return Complex(re + b.re, img + b.img);
	}
	Complex operator=(Complex b) {
		return Complex(re = b.re, img = b.img);
	};
	Complex operator *(complex b) {
		int temp_re;
		float temp_im;
		temp_re = re * b.re;
		temp_im = img*b.img;
		return(temp_re, temp_im);
	}

};
int main() {
	Complex a(1.0, 1.0);
	Complex* b = new Complex(5.0);
	Complex c(0, 0);
	Complex result(0,0);
	cout << "a real =" << a.Real() << " a imaginary =" << a.Img();
	cout << "b real =" << b->Real() << " b imaginary =" << a.Img();
	c = a +(* b);
	cout << "c real = " << c.Real() << "c imaginary =" << c.Img();
	result=a* c;
	cout << result;
	delete b;
	return 0;
}*/


//EXERCISE 1.2
/*include <iostream>
using namespace std;

template <class T>
class mypair
{
    T a, b;
public:
    mypair(T first, T second)
    {
        a = first;
        b = second;
    }

    T getmin();
};

template <class T>
T mypair<T>::getmin()
{
    T min;
    min = a < b ? a : b;
    return min;
}

int main()
{
    mypair<int> myobject(100, 75);
    cout << myobject.getmin();
    return 0;
}*/


//EXERCISE:1.3:
/*#include <iostream>
using namespace std;

template <class T, int N>
class mysequence
{
    T memblock[N];
  public:
    void setmember(int x, T value);
    T getmember(int x);
    T getMaximum();
    T getMinimum();
};

template <class T, int N>
void mysequence<T, N>::setmember(int x, T value)
{
    memblock[x] = value;
}

template <class T, int N>
T mysequence<T, N>::getmember(int x)
{
    return memblock[x];
}

template <class T, int N>
T mysequence<T, N>::getMaximum()
{
    T max = memblock[0];
    for (int i = 1; i < N; i++)
    {
        if (memblock[i] > max)
        max = memblock[i];
    }
    return max;
}

template <class T,int N>
T mysequence<T, N>::getMinimum()
{
    T min = memblock[0];
    for (int i = 1; i < N; i++)
    {
        if (memblock[i] < min)
        min = memblock[i];
    }
    return min;
}
int main()
{
    mysequence<int, 4> myints;
    mysequence<double, 3> myfloats;

    myints.setmember(0, 100);
    myints.setmember(1, 23);
    myints.setmember(2, 758);
    myints.setmember(3, 22);

    myfloats.setmember(2, 3.1416);
    myfloats.setmember(1, 333);
    myfloats.setmember(0, 3);

    cout << myints.getMaximum() << '\n';
    cout << myfloats.getMinimum() << '\n';

    return 0;
}*/

//EXERCISE:1.4 :
   /* #include <iostream>
    #include <fstream>
    
    using namespace std;
    
    int main(void)
    {
        ofstream outFile;
        outFile.open("fout.txt");
    
        ifstream inFile("fin.txt");
    
        char ch;
        int charCount = 0;
        int wordCount = 0;
        int sentenceCount = 0;
        bool inWord = false;
    
        while (inFile.get(ch))
        {
            outFile << ch;
            charCount++;
    
            // Check for word boundaries
            if (ch == ' ' || ch == '\t' || ch == '\n') {
                if (inWord) {
                    wordCount++;
                    inWord = false;
                }
            }
            else {
                inWord = true;
            }
    
            // Check for sentence boundaries
            if (ch == '.' || ch == '!' || ch == '?') {
                sentenceCount++;
            }
        }
    
        // If the file ends with a word, count it
        if (inWord) {
            wordCount++;
        }
    
        outFile << "\n\nCharacter count = " << charCount << endl;
        outFile << "Word count = " << wordCount << endl;
        outFile << "Sentence count = " << sentenceCount << endl;
    
        inFile.close();
        outFile.close();
    
        return 0;
    }*/


    //EXERCISE:1.5:
    /*#include <iostream>
    #include <iomanip>
    #include <string>
    
    using namespace std;
    class House {
    public:
        string owner;
        string address;
        int bedrooms;
        float price;
        void readData() {
            cout << "Enter Owner: ";
            getline(cin, owner);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Number of Bedrooms? : ";
            cin >> bedrooms;
            cout << "Price: ";
            cin >> price;
            cin.ignore();  
        }
        void displayData() const {
            cout << left << setw(15) << owner
                << left << setw(20) << address
                << left << setw(10) << bedrooms
                << left << setw(10) << price << endl;
        }
    };
    
    int main() {
        House available[100]; 
        int count = 0;
        char choice;
    
       
        do {
            available[count].readData();
            count++;
    
            cout << "\nEnter another house? (Y/N): ";
            cin >> choice;
            cin.ignore();  
        } while (toupper(choice) == 'Y' && count < 100);
    
        cout << "\nThe output should look like:\n";
        cout << left << setw(15) << "Owner"
            << left << setw(20) << "Address"
            << left << setw(10) << "Bedrooms"
            << left << setw(10) << "Price" << endl;
    
        for (int i = 0; i < count; i++) {
            available[i].displayData();
        }
    
        return 0;
    }*/


    //EXERCISE:1.6:
    /*#include <iostream>
    #include <fstream>
    #include <iomanip>
        using namespace std;
    
    class Student {
    private:
        string name;
        int grades[10];
        float average;
        int numGrades;
    
    public:
        void setName(const string& n) {
            name = n;
        }
    
        void setGrades(int* g, int count) {
            numGrades = count;
            for (int i = 0; i < count; ++i) {
                grades[i] = g[i];
            }
        }
    
        void computeAverage() {
            int sum = 0;
            for (int i = 0; i < numGrades; ++i) {
                sum += grades[i];
            }
            average = static_cast<float>(sum) / numGrades;
        }
    
        float getAverage() const {
            return average;
        }
    
        string getName() const {
            return name;
        }
    
        void display() const {
            cout << left << setw(20) << name;
            for (int i = 0; i < numGrades; ++i) {
                cout << setw(6) << grades[i];
            }
            cout << setw(8) << fixed << setprecision(2) << average << endl;
        }
    };
    
    int main() {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;
    
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file." << endl;
            return 1;
        }
    
        int numStudents, numGrades;
        file >> numStudents >> numGrades;
    
        Student students[100]; // Assuming a maximum of 100 students
        int grades[10]; // Assuming a maximum of 10 grades per student
    
        for (int i = 0; i < numStudents; ++i) {
            string firstName, lastName;
            file >> firstName >> lastName;
            students[i].setName(firstName + " " + lastName);
    
            for (int j = 0; j < numGrades; ++j) {
                file >> grades[j];
            }
            students[i].setGrades(grades, numGrades);
            students[i].computeAverage();
        }
    
        float classAverage = 0;
        for (int i = 0; i < numStudents; ++i) {
            classAverage += students[i].getAverage();
        }
        classAverage /= numStudents;
    
        cout << left << setw(20) << "Name" << setw(6 * numGrades) << "Grades" << "Average" << endl;
        for (int i = 0; i < numStudents; ++i) {
            students[i].display();
        }
    
        cout << "\nClass Average: " << fixed << setprecision(2) << classAverage << endl;
    
        int maxIndex = 0, minIndex = 0;
        for (int i = 1; i < numStudents; ++i) {
            if (students[i].getAverage() > students[maxIndex].getAverage()) {
                maxIndex = i;
            }
            if (students[i].getAverage() < students[minIndex].getAverage()) {
                minIndex = i;
            }
        }
    
        cout << "Highest Average: " << students[maxIndex].getAverage() << " (" << students[maxIndex].getName() << ")\n";
        cout << "Lowest Average: " << students[minIndex].getAverage() << " (" << students[minIndex].getName() << ")\n";
    
        cout << "\nStudents below class average:\n";
        for (int i = 0; i < numStudents; ++i) {
            if (students[i].getAverage() < classAverage) {
                cout << students[i].getName() << " (" << students[i].getAverage() << ")\n";
            }
        }
    
        return 0;
    }*/
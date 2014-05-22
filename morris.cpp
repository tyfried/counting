#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
#include <fstream>

using namespace std;



int main()
{
	//const int n = 8; //n bit register
	int counter = 0; int morris = 0;
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	unsigned seed2 = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	
	//implementation 1
	bernoulli_distribution distribution(0.5);
	mt19937 gen(seed2);
	
	int runtime = 0;
	ofstream out;
	out.open("3000.dat");
	int temp;
	while (runtime++ < 10000){
		//int n = gen()%49744 + 256;
		int n = 2048;
		counter = morris = 0;
		while (counter<n){
			counter++;
			int x = 1;
			int ceil = morris;
			for (int i=0; i<ceil; i++){
				x&= distribution(generator);
			}
			morris+=x;
			// if (x){
				// cout << "morris=" << morris << ", counter=" << counter << endl;
			// }
		}
		temp = pow(2,morris);
		out << counter << " "  << morris << " " << temp << " " << counter - temp << endl;
		cout << n << endl;
	}
	out.close();
	
	// cout << "FINAL RESULTS" << endl;
	// cout << "morris=" << morris << endl;
	// cout << "pow(2,morris)=" << pow(2,morris) << endl;
	// cout << "counter=" << counter << endl;
	return 0;
}

//implementation 2
// uniform_real_distribution<double> distribution(0.0,1.0);
// while (counter<2048){
	// counter++;
	// double temp = exp(1.0*morris+1.0)-exp(1.0*morris);
	// if ((1.0/temp) > distribution(generator)) morris++;
// }
//cout << "exp(morris)=" << exp(morris) << endl;
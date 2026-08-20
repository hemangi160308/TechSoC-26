#include <iostream>
using namespace std;

int main()
{
    int N,C;
    cout << "Enter capacity: ";
    cin >> C;
    cout << "Enter number of containers: ";
    cin >> N;
    while (N<1 || N >1000)
    {
        cout << "Invalid number of containers" << endl;
        cout << "Enter again: ";
        cin >> N;
    }
        double weight [N];
    for (int i = 0; i < N; i++)
    {
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> weight[i];
    }
     double total = 0, avg = 0, l = 0, h = 0;
     for (int i = 0; i < N; i++)
    {
        total += weight[i];
    }
    avg = total/N;
    for(int i=0; i<N; i++)
    {
    
       
      if(h < weight[i])
      {
         h = weight[i];
      }
    }
     l = weight[0];
      for(int i=1; i<N; i++)
    {
       
      if(l > weight[i])
      {
         l = weight[i];
      }
    }
    cout << "Total Shipment Weight: " << total << endl;
    cout << "Average Container Weight: " << avg << endl;
    cout << "Heaviest Container: " << h << endl;
    cout << "Lightest Container:  " << l << endl;
    if (total<=200)
    {
        cout <<"Light"<< endl;
    }
    else
    {
        cout << "Heavy" << endl;
    }
    if (total<=C)
    {
        cout <<"Shipment can be unloaded"<< endl;
    }
    else
    {
        cout << "Shipment exceeds port capacity" << endl;
    }
    return 0;
}
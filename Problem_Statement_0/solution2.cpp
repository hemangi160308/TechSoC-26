#include <iostream>
using namespace std;
void sortedW(double weight[], int N)
{
   double t = 0.0;
   for(int i=0; i<N; i++)
   {
    for(int j=0; j<N-i-1; j++)
    if(weight[j]>weight[j+1])
    {
        t = weight[j];
        weight[j] = weight[j+1];
        weight[j+1] = t;
    }
    
   }
   cout << "Sorted weights: ";
   for(int i=0; i<N; i++)
   {
     cout << weight[i] << " ";
    
   }
   cout << "" << endl;
}
void barChart(double weight[], int N)
{
     cout << "Container Weight Bar Chart: " << endl;
    for(int i = 0; i<N; i++)
    {
        cout << "Container " <<  i+1 << ": ";
        for(int j = 0; j < weight[i]/5; j++)
        {
        cout << "*";
        
        }
        cout << "" << endl;
    }

}
void searchW(double sw, int N, double weight[])
{
    int t;
  cout << "Enter weight: "<< endl;
  cin >> sw;
  for(int i=0; i<N; i++)
  {
    if (sw == weight[i])
    {
         t = 1;
    }

  }
  if (t == 1)
  {
    cout << "Container found" << endl;
  }
  else 
  {
    cout << "Container not found" << endl;
  }

}
int main()
{   
    int N,C;
    double sw;
    int p;
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

    int k = 0;
    cout << "MENU" << endl;
    cout << "1. See cargo details" << endl;
    cout << "2. Display Sorted weights" << endl;
    cout << "3. Display Bar Chart" << endl;
    cout << "4. Search for container" << endl;
    cout << "5. Exit" << endl;
   
    do
    {
     cout << "Enter choice (1/2/3/4/5)" << endl;
     cin >> k;
    
    if (k==1)
    {
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
    }
    else if(k==2)
    {
      sortedW(weight,N);
    }
    else if(k==3)
    {
      barChart(weight,N);
    }
    else if(k==4)
    {
      searchW(sw, N, weight);
    }
    else if (k==5)
    {
        cout << "exiting" << endl;
    }
    else 
    {
        cout << "Invalid choice" << endl;
    }
    } while (k!=5);
    
    return 0;
}
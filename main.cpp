#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;

void AntyPrzekatna1(int M, int N, vector<vector<int>> tab)//Najbardziej optymalny algorytm
{
    int i=0, j=0;
    int imin=0, imax=0;
    for(int p=0;p<=M+N-2;p++){
        imin=max(0,p-(N-1));
        imax=min(p, (M-1));
        i=imax;
        while(i>=imin){
            j=p-i;
            cout<<tab[i][j]<<" ";
            i--;
        }
        cout<<endl;
    }
}

void AntyPrzekatna2(int M, int N, vector<vector<int>> tab)//Mniej optymalny algorytm
{
    int pmax = (M-1)+(N-1);
    for(int p=0;p<=pmax;p++){
        for(int i=M-1;i>=0;i--){
            for(int j=0;j<N;j++){
                if(i+j==p){
                    cout<<tab[i][j]<<" ";
                }
            }

        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);//Przyspieszenie operacji wejscia wyjscia
    cin.tie(NULL);
    fstream plik;
    plik.open("Proba.txt", ios::in);//Uzyskanie dostepu do pliku

    int M,N;

    cin>>M>>N;
    //plik>>M>>N;
    vector<vector<int>> tab (M, vector<int>(N)); //Tworzenie vectora dwuwymiarowego o rozmiarach MxN
    srand(time(NULL)); //Generowanie pseudo losowych
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
             tab[i][j]=rand()%10;
        }
    }

    /*for(int i=0;i<M;i++){//Wczytywanie danych z pliku
        for(int j=0;j<N;j++){
            plik>>tab[i][j];
        }
    }*/


    /*for(int i=0;i<M;i++){//Wyswietlenie tablicy przed wykonaniem algorytmu
        for(int j=0;j<N;j++){
             cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }*/
    //Porownywanie czasu algorytmow
    auto start = std::chrono::high_resolution_clock::now();
    AntyPrzekatna1(M,N,tab);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Czas wykonywania: " << duration.count() << " ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    AntyPrzekatna2(M,N,tab);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Czas wykonywania: " << duration.count() << " ms" << std::endl;


    plik.close();

    return 0;
}

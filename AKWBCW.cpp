#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <conio.h>


using namespace std;
int numer,nr,num,n,m,i,j,v1,v2,sprzezony=0,check=0,check2=0, nastepniki=0,lin1,lin2,lin3,warunek1=0,q,q1=0,y,warunek2=0,c,c1,c2,warunek3=0,**oryginalny, ** A;

void transformacja(int n, int **A,ofstream &zapis)
{ cout<<"graf oryginalny :"<<endl;

int wierzcholek = 2;
int ilosc =0;




    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {

            if(A[a][b]>0)
            {
                if(A[a][b]==1)
                {
                    A[a][b]=wierzcholek;
                    wierzcholek++;
                }
                for(int a2=0; a2<n; a2++)
                {
                    if(A[b][a2]>0)
                    {
                        if(A[b][a2]==1)
                        {
                            A[b][a2]=wierzcholek;
                            wierzcholek++;
                        }
                        cout<<a<<","<<b<<" ->  "<<b<<","<<a2<<endl;
                        ilosc++;
                        //a<<","<<b,



                    }
                }


            }

    }
    }





  zapis<<wierzcholek-2<<" ";
  zapis<<ilosc<<endl;
  for(int a2=0; a2<n; a2++)
    {
        for(int b2=0; b2<n; b2++)
        {

            if(A[a2][b2]>0)
            {

                for(int a22=0; a22<n; a22++)
                {
                    if(A[b2][a22]>0)
                    {

                        zapis<<A[a2][b2]-2<<" "<<A[b2][a22]-2<<endl;





                    }
                }


            }

    }
    }

return;};





int main()
{


    std::fstream plik;
    plik.open( "exa1.txt", std::ios::in );
    if( plik.good() == true )
    {
        std::cout << "Uzyskano dostep do pliku!" << std::endl;

    }
    else
        std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;



    plik>>n;
    plik>>m;
    cout<< "liczba wierzcholkow:";
    cout << n<<endl;
    cout.width(2);
    cout<< "liczba krawedzi:";
    cout << m <<endl;


    A = new int * [n];

    for(i = 0; i < n; i++){
        A[i] = new int [n];}

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            A[i][j] = 0;}}

    for(i = 0; i < m; i++)
        {
        plik >> v1 >> v2;
        A[v1][v2] += 1;
        if(A[v1][v2]>1)
        {
            sprzezony+=1;
        }

    }


     if(sprzezony>0)
    {
        cout<<"nie jest to 1 graf" <<endl;
        getch();
    }else{

    for(nr=0; nr < n; nr++)
    {
        for(num=0; num<n; num++)
        {
            for(numer=0; numer<n; numer++)
            {
               if(nr!=num){
                if(A[nr][numer]&& A[num][numer])
                {
                    check+=1;
                }
                if(numer==n && check>0)
                {
                    for(numer=0; numer<n; numer++)
                    {
                        if(A[nr][numer]|| A[num][numer])
                        {
                            check2+=1;
                        }

                    }
                     if(check2!=check)
                    {
                        nastepniki+=1;
                    }




                }

            }}

        }
    }

    }//od elsea
    int h=0,g=0,u;

    if(nastepniki>0)
    {
        cout<<"blad nastepnikow"<<endl;
    }
    //1 podgraf wykluczajacy liniowy
    for( h;h<n;h++){
            u=0;
            lin1=0;
        for(g=0;g<n;g++){
            if(A[h][g]==1){
            lin1+=1;


            }

            if(lin1>=2){
                     int * tablica = new int[lin1];
            for(g=0;g<n;g++){
            if(A[h][g]==1){

            tablica[u]=g;

            u++;

            }

            }
            //przyrownanie n+ n+ od 1-ego V
            for(int r=0;r<lin1;r++){
                for(int r2=0;r2<lin1;r2++){
                    for(int r3=0;r3<n;r3++){
                            if(r!=r2){
                                if(A[tablica[r]][r3]&&A[tablica[r2]][r3]){
                                        warunek1+=1;

                                }
                            }

                    }
                }
            }


        }
        }
    }
        if(warunek1>=1){
            cout<<"wystepuje 1 struktura wykluczajaca graf liniowy"<<endl;
        }
//2struktura wykluczajaca graf liniowy
    for(q=0;q<n;q++){
        for(q1=0;q1<n;q1++){

            if(q!=q1){
            if(A[q][q1]&&A[q1][q]){

                    for(y=0;y<n;y++){
                            if(q!=y){
                        if(y!=q1){
                        if(A[q][y]&& A[y][q]){

                            warunek2++;
                        }}}
                        if(q1!=y){
                                if(y!=q){
                        if(A[q1][y]&& A[y][q1]){

                            warunek2++;
                        }}}
                    }}

            }
        }}


if(warunek2>=1){
    cout<<"wystepuje 2 struktura wykluczajaca graf liniowy"<<endl;
}

for(c=0;c<n;c++){
    if(A[c][c]){
        for(c1=0;c1<n;c1++){
            if(c!=c1){
                if(A[c][c1]&&A[c1][c]){
                    if(A[c1][c1]){
                        warunek3++;
                    }
                }
            }
        }
    }
}

if(warunek3>=1){
    cout<<"wystepuje 3 struktura wykluczajaca graf liniowy"<<endl;
}
cout<<endl;
for(int qq=0;qq<n;qq++){
        cout<<qq<<":";
    for(int qqq=0;qqq<n;qqq++){
        if(A[qq][qqq]>0){
            cout<<qqq;
            cout<<" ";

        }


    }
    cout<<endl;
}
ofstream zapis;
    zapis.open("wynik.txt");
transformacja(n,A,zapis);
zapis.close();






    return 0;
}

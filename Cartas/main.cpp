 #include <iostream>

using namespace std;

void arrange(int x[]) {

    for(int n=0; n<15;n++){
        for(int n2=n+1;n2<15;n2++){
           if( x[n]==x[n2] ){
              for(int y=n2;y<15;y++){
                  x[y]=x[y+1];

              }

           }

        }
    }


}

int main()
{
    int x[15]= {1,5,6,7,8,4,2,3,2,3,4,3,8,1,4};
    arrange(x);
    cout << "Numeros" << endl;
    for(int n=0;n<15;n++){
        if(x[n]==NULL)
            break;
        cout << x[n]<<endl;


    }

    return 0;
}


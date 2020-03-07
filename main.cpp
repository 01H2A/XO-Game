#include <iostream>
using namespace std;

void print_mat(char mat[][3])
{
    for(int i =0 ; i<3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cout<<" "<<mat[i][j]<<" ";
            if(j != 2)
                cout<<"|";
        }
        if(i==2)
        {
            cout<<"\n\n";
            continue;
        }

        else
            cout<<"\n-----------\n";
    }

}

void p_turn(string p1,string p2,int x)
{
    if(x % 2 != 0)
        cout<<p1<<"'s Turn\n";
    else
        cout<<p2<<"'s Turn\n";
}

void change(char mat[][3], int r , int c, int turn)
{
    if(turn % 2 != 0)
        mat[r][c]='x';
    else
        mat[r][c]='o';

    cout<<"\n";
}
string check(char mat[][3],string p1,string p2,int turn)
{
    char symp;
    int n=0; // Number of continuous matching
    string player;

    if(turn % 2 != 0)
    {
        symp='x';
        player = p1;
    }
    else
    {
        symp='o';
        player = p2;
    }


    for(int i =0 ; i <3 ; i++)
    {
        for(int j =0 ; j<3 ; j++)
        {
            if(mat[i][j] == symp)
                n++;
        }
        if(n == 3)
            return player;
        else
            n=0;
    }

    for(int i =0 ; i <3 ; i++)
    {
        for(int j =0 ; j<3 ; j++)
        {
            if(mat[j][i] == symp)
                n++;
        }
        if(n == 3)
            return player;
        else
            n=0;
    }
    n=0;

    for(int i =0 ; i <3 ; i++)
        if(mat[i][i] == symp)
                n++;
    if(n == 3)
        return player;
    else
        n=0;

    for(int i =0 ; i <3 ; i++)
        if(mat[i][3-i-1] == symp)
                n++;

    if(n == 3)
        return player;
    else
        n=0;

    return " ";
}
int main()
{
    system("color 0a");
    char mat[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    string p1 , p2 ;


    cout<<"Enter the name of player one : ";\
    cin>>p1;
    cout<<"Enter the name of player two : ";
    cin>>p2;
    system("cls");

    for(int turn = 1; turn <=9 ; turn++)
    {

        p_turn(p1,p2,turn);

        int r , c;
        cout<<"Enter Row Number : "; cin>>r;
        cout<<"Enter column Number : "; cin>>c;

        change(mat, r-1,c-1,turn);
        system("cls");
        print_mat(mat);


        if(check(mat,p1,p2,turn)== p1)
        {
            cout<<p1<<" Is The Winner\n\n";
            break;
        }
        else if(check(mat,p1,p2,turn)== p2)
        {
            cout<<p2<<" Is The Winner\n\n";
            break;
        }
        if(turn ==9)
            cout<<"Nobody Wins\n";
   }

    return 0;
}

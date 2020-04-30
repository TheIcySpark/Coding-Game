#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    int xI=0,xF=W,yI=0,yF=H,xM=X0,yM=Y0;
    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();
        if(bombDir=="U"){
            yF=yM-1;

        }else if(bombDir=="UR"){
            yF=yM-1;
            xI=xM+1;
            
        }else if(bombDir=="R"){
            xI=xM+1;
            
        }else if(bombDir=="DR"){
            xI=xM+1;
            yI=yM+1;
            
        }else if(bombDir=="D"){
            yI=yM+1;
            
        }else if(bombDir=="DL"){
            yI=yM+1;
            xF=xM-1;
            
        }else if(bombDir=="L"){
            xF=xM-1;
            
        }else if(bombDir=="UL"){
            xF=xM-1;
            yF=yM-1;
            
        }
        yM=(yI+yF)/2;
        xM=(xI+xF)/2;
        cout<<xM<<" "<<yM<<endl;
    }
}
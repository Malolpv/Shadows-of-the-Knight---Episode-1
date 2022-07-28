#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


int main()
{
    
    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();
    double bx = x0;
    int by = y0;

    int w0 = 0;//x0 de la box avant triangulisation
    int h0 = 0;//y0 de la box avant triangulisation
    
    // game loop
    while (1) {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();
        cerr<<h0<<" "<<by<<" "<<h0+by<<" "<<(h0+by)/2.0<<endl;
        cerr<<"round : "<<floor(double((h0+by)/2.0))<<endl;

        for(auto&c:bomb_dir)
        {
            cerr<<"Direction : "<<c<<endl;
            if(c == 'U')
            {
                h=by;
                by=floor(double((h0+by)/2.0))+((floor((h0+by)/2)-2>=0)?-2:0);
            }
            else if(c == 'R')
            {
                w0 = bx;
                bx+=floor((w-bx)/2);
            }
            else if(c == 'L')
            {
                w = bx;
                bx = floor((w0+bx)/2);
            }
            else if(c == 'D')
            {
                h0 = by;
                by+=floor((h-by)/2);
            }
        }
        
        cout<<bx <<" "<<by<<endl;
    }
}
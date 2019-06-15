#include "View.h" 

using namespace std;

View::View(){
	size = 11;
	scale = 2;
	origin = Cart_Point();
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

void View::clear(){
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

bool View::get_subscripts(int &ix, int &iy, Cart_Point location){
	Cart_Vector p1 = (location - origin) / scale;
	ix = p1.x;
	iy = p1.y;
	if(ix <= size && iy <= size){
		return true;
	}
	else{
		cout << "An object is outside the display" << endl;
		return false;
	}
}

void View::plot(Game_Object* ptr){
	Cart_Point loc = ptr->get_location();
	int x;
	int y;
	char self[2];
	if(get_subscripts(x, y, loc)){
		ptr->drawself(self);
		if(grid[x][y][0] == '.'){
			grid[x][y][0] = self[0];
			grid[x][y][1] = self[1];
		}
		else{
			grid[x][y][0] = '*';
			grid[x][y][1] = ' ';			
		}
	}
}

void View::draw(){
	int xAxisVal = 0;
	int yAxisVal = scale*(size-1);
	cout << endl;
	for(int i = 0; i < size; ++i){
		if(i == 0 || i%2 == 0){
			if(yAxisVal < 10)
				cout << yAxisVal << " ";
			else
				cout << yAxisVal;
			yAxisVal -= 2*scale;
		}
		else{
			cout << "  " ;
		}
		for(int j = 0; j < size; ++j){
			cout << grid[j][size-1-i][0] << grid[j][size-1-i][1];
		}
		cout << endl;
	}
	cout << "  ";
	for(int k = 0; k < size; ++k){
		if(k == 0 || k%2 == 0){
			cout << xAxisVal;
			if(xAxisVal < 10){
				cout << "   ";
			}
			else{
				cout << "  ";
			}
			xAxisVal += 2*scale;
		}
	}
	cout << endl;
}
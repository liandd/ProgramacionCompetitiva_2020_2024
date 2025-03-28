#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct circle{
  double x;
  double y;
  double r;
  double speed;

};


double Dist(circle C1, circle C2){
  return sqrt(pow(C1.x-C2.x,2)+pow(C1.y-C2.y,2));
}

void Come_On_Baby_Print_My_Circles(const vector<circle>& v){
  for(int i = 0; i < v.size(); i++){
    cout << "Circle " << i << ": ";
    cout << "(" << v[i].x << "," << v[i].y << ") ";
    cout << "r: " << v[i].r << " " << "speed: " << v[i].speed << endl;
  }
}

	      
// returns the time till the next collision.  If they are already overlapping,
// return 0
double Get_Collision_Time(circle C1, circle C2){
  double d = Dist(C1, C2);
  d = d-C1.r-C2.r;
  if(d <= 0) // they are touching
    return 0;
  double t = d/(C1.speed+C2.speed);
  return t;
  
}

circle Make_New_Circle(const vector<circle>& circle_list, const vector<int>& colliders,  double time){
     //cout << "Collision with: ";
  circle new_circle;
  new_circle.x = 0;
  new_circle.y = 0;
  new_circle.r = 0;
  new_circle.speed = 0;
  double area = 0;
  for(int i = 0; i < colliders.size(); i++){
       //  cout << colliders[i] << " (";
    circle temp = circle_list[colliders[i]];
    new_circle.x += temp.x;
    new_circle.y += temp.y;
    new_circle.r += pow(temp.r + temp.speed*time, 2);
    if(temp.speed > new_circle.speed)
      new_circle.speed = temp.speed;
  //  cout << temp.x << ' ' << temp.y << ' ' << temp.r << ' ' << temp.speed << ") ";
  }
  new_circle.r = sqrt(new_circle.r);
  new_circle.x = new_circle.x/colliders.size();
  new_circle.y = new_circle.y/colliders.size();
 // cout << " at time " << time << endl;
//  if (colliders[0] == 46 && colliders[1] == 48) {
//    for (int i=0;i<circle_list.size();i++)
//      if (circle_list[i].speed == 83991 || circle_list[i].speed == 256120)
//        cout << "---" << circle_list[i].x << ' ' << circle_list[i].y << ' ' << circle_list[i].r << "---"
//        << endl;
//  }
  return new_circle;
}

bool Find(const vector<int>& v, int key){
  for(int i = 0; i < v.size(); i++)
    if(v[i] == key)
      return true;
  return false;
}

void Swap(circle& x, circle& y){
  circle temp = x;
  x = y;
  y = temp;
}

int main(){
  int n;
  cin >> n;
  vector<circle> circle_list(n);
    for(int i = 0; i < n; i++){
    cin >> circle_list[i].x;
    cin >> circle_list[i].y;
    cin >> circle_list[i].r;
    cin >> circle_list[i].speed;
  
  }
  while(circle_list.size() > 1){
    // Come_On_Baby_Print_My_Circles(circle_list);
    double next_collision = 2000000000;
    
    vector<int> colliders;
    for(int i = 0; i < circle_list.size(); i++)
      for(int j = i+1; j < circle_list.size(); j++){
	double collision_time = Get_Collision_Time(circle_list[i], circle_list[j]);
	if(collision_time < next_collision){
	  next_collision = collision_time;
	  colliders.resize(0);
	  colliders.push_back(i);
	  colliders.push_back(j);
	}
	else if(collision_time == next_collision){ // maybe some kind of epsilon thing
	  if(!Find(colliders, i) && !Find(colliders,j)){
	    cout << "Oh No!  Multiple collisions at time " << collision_time << endl;
	    exit(1);
	  }
	  if(circle_list.size() == n && collision_time == 0){
	    cout << "Error- collision at time 0!" << endl;
	    exit(1);
	  }
	  
	  if(!Find(colliders, i))
	    colliders.push_back(i);
	  else
	    colliders.push_back(j);
	}
      }
    if(colliders.size() > 2 && next_collision > 0){
      cout << "Error- " << colliders.size() << " collisions at time " << next_collision << endl;
      exit(1);
    }
    
    circle combined_circle = Make_New_Circle(circle_list, colliders, next_collision);
    vector<circle> new_circle_list;
    for(int i = 0; i < circle_list.size(); i++){
      if(!Find(colliders, i)){
	circle temp = circle_list[i];
	temp.r += temp.speed*next_collision;
	new_circle_list.push_back(temp);
      }
    }
    circle_list = new_circle_list;
    circle_list.push_back(combined_circle);
  }
  cout << fixed << setprecision(8) << circle_list[0].x << " " << circle_list[0].y << endl;
  cout << fixed << setprecision(8) << circle_list[0].r << endl;
  return 0;
}

  

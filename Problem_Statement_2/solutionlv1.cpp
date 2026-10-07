#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Bender
{
  public :

  string name, element;
  int hp, attack, defense, speed, hp_new;

 
 struct move
 {
   string move_name;
   int move_power;
   
 };
 move moves[4];
 Bender(string n, string e, int h, int a, int d, int s, move m[])
 {
   name = n;
   element = e;
   hp = h;
   attack = a;
   defense = d;
   speed = s;
   hp_new = h;


   for(int i=0; i<4; i++)
   {
    moves[i] = m[i]; 
   }
 }
 void display_stats()
 {
    cout << name << " (" << element;
    cout << ") - HP: " << hp_new << "/" << hp << ", Attack: ";
    cout << attack << ", Defense: " << defense << ", Speed: " << speed << endl;
    cout << "Moves: ";
    for(int i=0; i<4; i++)
    {
      cout << moves[i].move_name << " (" << moves[i].move_power << "), ";
    }
    cout << "" << endl;
    cout << "" << endl;
 }
 void battle(Bender &defender, int move_index)
 {
   string attack_used = moves[move_index].move_name;
   int damage = round((attack*moves[move_index].move_power)/defender.defense);
   cout << name << " used " << attack_used << "!" << endl;
   cout << defender.name << " took " << damage << " damages!" << endl;
   defender.hp_new = defender.hp_new - damage;
   if (defender.hp_new < 0)
   {
    defender.hp_new = 0;
   }
   cout << "" << endl;
   
 }
 void is_fainted()
 {
    if(hp==0)
    {
        cout << name << " fainted: True";
    }
    else
    {
        cout << name << " fainted: False";
    }
 }

};
int main()
{   
    Bender :: move Lugia_move[4] = {{"Tidal Crush", 82}, {"Aqua Lance", 75}, {"Healing Rain", 25}, {"Maelstorm", 90}}; 
    Bender :: move Moltres_move[4] = {{"Inferno Wing", 88}, {"Flame Burst", 82}, {"Volcano Fury", 95}, {"Pheonix Rebirth", 35}}; 
    Bender Lugia("Lugia", "Water", 170, 78, 95, 82, Lugia_move);
    Bender Moltres("Moltres", "Fire", 90, 94, 72, 88, Moltres_move);
    Lugia.display_stats();
    Moltres.display_stats();
    Moltres.battle(Lugia, 2);
    Lugia.display_stats();
    Lugia.is_fainted();
    return 0;
}
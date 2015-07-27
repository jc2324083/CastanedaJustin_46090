
 /* 
 * File:   main.cpp
 * Author: Justin Castaneda
 * Created on July 20, 2015, 1:20 PM
 * Purpose: Text Based RPG_V3
 */
//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//User Libraries

//Global Constant

//Function Prototypes
int cStatus(int,int,int);
int cAtk(int,int);
int mAtk(int,int);
int chrgAtk(int,int);
void title();
void begin();

//Engage!
int main(int argc, char** argv) {
    //Set Random Number
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Array
    const int SIZE=5;       //Size of the array
    int shipPC[SIZE];       //Ship pass code
    string map[5][5];          //Map OF SPACE!!(Space coordinates)
    /*
     Will feature a space travel between planets with coordinates from the array
     */
    
    //Declare and Initialize Variables
    int hp=175;             //User's Starting Health Power
    int gp=50;              //User's Starting Gun Power
    int nc=3;               //Number of Nova Crystal Shards
    int monHP=275;          //Monster's Starting Health Points
    int command;            //Inputting command
    int anyKey;             //To continue
    
    //Output Game Intro
    title();
    cin.get();
    
    //Begin Game
    begin();
   
    //Battle Sequence
    do{
        //Selecting a command
        cout<<endl;
        cout<<"Select 1 to Attack, Select 2 to use Nova Crystal Shard, Select 3 to use Charged Cannon"<<endl;
        cout<<"Input command...";
        cin>>command;
        cout<<endl;
        
        //Command 1 Attack
        if (command==1){
            int attack=cAtk(10,1);      //Initiates Player's Attack
            cout<<"You did "<<attack<<" damage to the creature."<<endl;
            monHP=monHP-attack;         //Subtracts from monster
            int mAttack=mAtk(15,1);     //Initiates Monster's Attack
            cout<<"The Creature did "<<mAttack<<" damage to you."<<endl;
            hp=hp-mAttack;              //Subtracts from player
            cStatus(hp,gp,nc);          //Displays current Status
            
        
        //Command 2 Healing
        }else if(command==2){
            if(nc<1){       //When nc<1 the player can't recover no more
                cout<<"You have no more Nova Crystals"<<endl;
            }else{
                int healHP=50;      //Recovers HP
                int healGP=15;      //Recovers GP
                hp=hp+healHP;
                gp=gp+15;
                nc=nc-1;
                cStatus(hp,gp,nc);
            }

        //Command 3 Charge Shot Takes two turns
        }else if(command==3){
            if(gp<15){              //When GP is less then 15 Charge Attack cant be used
                cout<<"You have no more GP to execute a charged attack!"<<endl<<endl;
            }else{
            //Charging Weapon Turn 1
            cout<<"You charge your gun to do a powerful attack"<<endl;
            int mAttack=mAtk(15,1);
            cout<<"The Creature did "<<mAttack<<" damage to you."<<endl<<endl;
            hp=hp-mAttack;
            cStatus(hp,gp,nc);
            
            //Turn 2 Fire Charge Shot
            cout<<"Press any number to unleash charged attack! ";
            cin>>anyKey;            //Continues Attack
            int chargeA=chrgAtk(20,1);  //Initiates Player's Charge Attack
            cout<<"Your charge shot did "<<chargeA<<" damage to the creature."<<endl;
            monHP=monHP-chargeA;
            int mAttck=mAtk(15,1);
            cout<<"The Creature did "<<mAttck<<" damage to you."<<endl<<endl;
            hp=hp-mAttck;
            gp=gp-15;               //Charge Attack uses 15 GP
            cStatus(hp,gp,nc);
            }
        }else{
            cout<<"Wow you put in a number I didn't ask for! Way to go!"<<endl;
            cout<<"Break the game! FINE! JEEZ!!!"<<endl;
        }
         
    //Until Character or Monster's HP reaches 0
    }while (hp>=0 && monHP>=0);{        
        }
    if (hp<=0){
        //Lost the game
        cout<<"The creature has defeated you!"<<endl;
        cout<<"------GAME OVER-----"<<endl;
        
        }else if (monHP<=0){
        //Won the game
        cout<<"The creature falls and is defeated!!"<<endl;
        cout<<"You search the body and collect the missing Nova Crystals that"<<endl;
        cout<<"the creature has stolen. You also find a security key to a door"<<endl;
        cout<<"You return back to ground base and decide to use the key on the lock door"<<endl;
        
        }        
    return 0;
}

/*****************************************************************************
 *************************** CHARACTER STATUS*********************************
 *                       h=hp                health power
 *                       g=gp                 gun power
 *                       n=nc                 nova crystals
 *****************************************************************************/
int cStatus(int h,int g, int n){
    cout<<"________________________________________________"<<endl;
    cout<<"***********Your HP is "<<h<<"/175***************"<<endl;
    cout<<"***********Your GP is "<<g<<"/50****************"<<endl;
    cout<<"***********You have "<<n<<" NCS left.************"<<endl<<endl;
}

/******************************************************************************
 *                                 Attack
 * ****************************************************************************
 * Input                                        
 *      amin=sides
 *      amax=rolls
 * Output
 *      Return Sum
 *****************************************************************************/
int cAtk(int amin,int amax){
    int sum;

    for (int atk=1;atk<=amax;atk++){
            sum=(rand()%amin+15);
            
            return sum;
            
        }
       
}
/******************************************************************************
 *                              Monster Attack
 * ****************************************************************************
 * Input                                        
 *      amin=sides
 *      amax=rolls
 * Output
 *      Return mSum
 *****************************************************************************/
int mAtk(int amin1,int amax1){
    int mSum;

    for (int atk=1;atk<=amax1;atk++){
            mSum=(rand()%amin1+15);
            
            return mSum;
        }
       
}

/******************************************************************************
 *                              Charged Shot
 * ****************************************************************************
 * Input                                        
 *      amin=sides
 *      amax=rolls
 * Output
 *      Return cSum
 *****************************************************************************/
int chrgAtk(int amin,int amax){
    int cSum;

    for (int atk=1;atk<=amax;atk++){
            cSum=(rand()%amin+32);
            
            return cSum;
        }  
}

/******************************************************************************
 *                              Title Screen                                  *
 ******************************************************************************/
void title(){
    cout<<"___________________________________________________________________"<<endl;
    cout<<"                                                                   "<<endl;
    cout<<"   *             o     *           +               +          *    "<<endl;
    cout<<"            *              o                      o                "<<endl;
    cout<<"          +            *      Space   *   *              *       + "<<endl;
    cout<<"      *            o         Voyager     *               * +       "<<endl;
    cout<<"        o +                       +                        *       "<<endl;
    cout<<"                  *     Press Enter to Start   *            o      "<<endl;
    cout<<"o  +*     o           *               *             *o             "<<endl;
    cout<<"___________________________________________________________________"<<endl<<endl<<endl<<endl;
}

void begin(){
    cout<<"\t\t\t******Space Voyager******"<<endl;
    cout<<"You received a distress signal from a ground station on Planet Bree "<<endl;
    cout<<"from the Alpha Centauri star system. When arriving you find that the "<<endl;
    cout<<"ground station was under attacked. Upon further searching you find a survivor "<<endl;
    cout<<"on their last breath."<<endl<<endl;
    cout<<"Survivor:A CREATURE DID THIS!! It came from the valley and attacked "<<endl;
    cout<<"us.It must of came for our resources for energy. It thrives off the"<<endl;
    cout<<"Nova Crystals that we mine here."<<endl<<endl;
    cout<<"Filled with rage, you head out into the valley for revenge and encounter"<<endl;
    cout<<"the creature."<<endl<<endl;
    cout<<"\tAll you have is your Galactic Gun and"<<endl;
    cout<<"\t3 Nova Crystal Shards(recovers 50 HP and 15 GP)"<<endl;
}
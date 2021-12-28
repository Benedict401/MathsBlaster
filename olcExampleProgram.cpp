#define OLC_PGE_APPLICATION

/* 
License(OLC - 3)
~~~~~~~~~~~~~~~

Copyright 2018 - 2020 OneLoneCoder.com

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met :

1. Redistributions or derivations of source code must retain the above
copyright notice, this list of conditionsand the following disclaimer.

2. Redistributions or derivative works in binary form must reproduce
the above copyright notice.This list of conditions and the following
disclaimer must be reproduced in the documentation and /or other
materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
contributors may be used to endorse or promote products derived
from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "olcPixelGameEngine.h"
#include <random>

class DimensionBlaster : public olc::PixelGameEngine
{
public:
	DimensionBlaster()
	{
		sAppName = "DimensionBlaster";
	}

	
	struct dimension {
	public:
		bool HasDimension;
		int idim;
		int kdim;
		int odim;
		std::string name;
	};

	struct grid {
	public:
		
		
		int top = 0; // This records how far the grid has moved down the screen, looks like time information might be necessary
	};

	//enum idim {R=0, i=1};
	//enum kdim {R=0, k1=1, k2=2, k3=3};
	//enum odim {R=0, o1=1, o2=2, o3=3, o4=4, o5=5, o6=6, o7=7 };

	enum SumTypes {	NoQuestion = 0, Addition = 1, Subtraction = 2, Multiplication = 3, Division = 4	};

	enum master {	R=0, i=1,
					k1=2, k2=3, k3=4, 
					o1=5, o2=6, o3=7, o4=8, o5=9, o6=10, o7=11,
					ik1=12, ik2=13, ik3=14,
					io1=15, io2=16, io3=17, io4=18, io5=19, io6=20, io7=21,
					k1o1=22, k1o2=23, k1o3=24, k1o4=25, k1o5=26, k1o6=27, k1o7=28,
					k2o1=29, k2o2=30, k2o3=31, k2o4=32, k2o5=33, k2o6=34, k2o7=35,
					k3o1=36, k3o2=37, k3o3=38, k3o4=39, k3o5=40, k3o6=41, k3o7=42,
					ik1o1=43, ik1o2=44, ik1o3=45, ik1o4=46, ik1o5=47, ik1o6=48, ik1o7=49,
					ik2o1=50, ik2o2=51, ik2o3=52, ik2o4=53, ik2o5=54, ik2o6=55, ik2o7=56,
					ik3o1=57, ik3o2=58, ik3o3=59, ik3o4=60, ik3o5=61, ik3o6=62, ik3o7=63 
	};

	//to make a game out of this we are going to need minus balls -, left multiply and right multiply

	struct DimensionVector {
		DimensionVector() {
			Dimension[R] = { 0,0,0,0,"R"}; //0
			Dimension[i] = { 1,1,0,0,"i"};		//1
			Dimension[k1] = { 1,0,1,0,"k1"};	//2
			Dimension[k2] = { 1,0,2,0,"k2"};	//3
			Dimension[k3] = { 1,0,3,0,"k3"};	//4
			Dimension[o1] = { 1,0,0,1,"o1"};	//5
			Dimension[o2] = { 1,0,0,2,"o2"};	//6
			Dimension[o3] = { 1,0,0,3,"o3"};	//7
			Dimension[o4] = { 1,0,0,4,"o4"};	//8
			Dimension[o5] = { 1,0,0,5,"o5"};	//9
			Dimension[o6] = { 1,0,0,6,"o6"};	//10
			Dimension[o7] = { 1,0,0,7,"o7"};	//11
			Dimension[ik1] = { 1,1,1,0,"ik1"};	//12
			Dimension[ik2] = { 1,1,2,0,"ik2"};	//13
			Dimension[ik3] = { 1,1,3,0,"ik3"};	//14
			Dimension[io1] = { 1,1,0,1,"io1"};	//15
			Dimension[io2] = { 1,1,0,2,"io2"};	//16
			Dimension[io3] = { 1,1,0,3,"io3"};	//17
			Dimension[io4] = { 1,1,0,4,"io4"};	//18
			Dimension[io5] = { 1,1,0,5,"io5"};	//19
			Dimension[io6] = { 1,1,0,6,"io6"};	//20
			Dimension[io7] = { 1,1,0,7,"io7"};	//21
			Dimension[k1o1] = { 1,0,1,1,"k1o1"};	//22
			Dimension[k1o2] = { 1,0,1,2,"k1o2"};	//23
			Dimension[k1o3] = { 1,0,1,3,"k1o3"};	//24
			Dimension[k1o4] = { 1,0,1,4,"k1o4"};	//25
			Dimension[k1o5] = { 1,0,1,5,"k1o5"};	//26
			Dimension[k1o6] = { 1,0,1,6,"k1o6"};	//27
			Dimension[k1o7] = { 1,0,1,7,"k1o7"};	//28
			Dimension[k2o1] = { 1,0,2,1,"k2o1"};	//29
			Dimension[k2o2] = { 1,0,2,2,"k2o2"};	//30
			Dimension[k2o3] = { 1,0,2,3,"k2o3"};	//31
			Dimension[k2o4] = { 1,0,2,4,"k2o4"};	//32
			Dimension[k2o5] = { 1,0,2,5,"k2o5"};	//33
			Dimension[k2o6] = { 1,0,2,6,"k2o6"};	//34
			Dimension[k2o7] = { 1,0,2,7,"k2o7"};	//35
			Dimension[k3o1] = { 1,0,3,1,"k3o1"};	//36
			Dimension[k3o2] = { 1,0,3,2,"k3o2"};	//37
			Dimension[k3o3] = { 1,0,3,3,"k3o3"};	//38
			Dimension[k3o4] = { 1,0,3,4,"k3o4"};	//39
			Dimension[k3o5] = { 1,0,3,5,"k3o5"};	//40
			Dimension[k3o6] = { 1,0,3,6,"k3o6"};	//41
			Dimension[k3o7] = { 1,0,3,7,"k3o7"};	//42
			Dimension[ik1o1] = { 1,1,1,1,"ik1o1"};	//43
			Dimension[ik1o2] = { 1,1,1,2,"ik1o2"};	//44
			Dimension[ik1o3] = { 1,1,1,3,"ik1o3"};	//45
			Dimension[ik1o4] = { 1,1,1,4,"ik1o4"};	//46
			Dimension[ik1o5] = { 1,1,1,5,"ik1o5"};	//47
			Dimension[ik1o6] = { 1,1,1,6,"ik1o6"};	//48
			Dimension[ik1o7] = { 1,1,1,7,"ik1o7"};	//49
			Dimension[ik2o1] = { 1,1,2,1,"ik2o1"};	//50
			Dimension[ik2o2] = { 1,1,2,2,"ik2o2"};	//51
			Dimension[ik2o3] = { 1,1,2,3,"ik2o3"};	//52
			Dimension[ik2o4] = { 1,1,2,4,"ik2o4"};	//53
			Dimension[ik2o5] = { 1,1,2,5,"ik2o5"};	//54
			Dimension[ik2o6] = { 1,1,2,6,"ik2o6"};	//55
			Dimension[ik2o7] = { 1,1,2,7,"ik2o7"};	//56
			Dimension[ik3o1] = { 1,1,3,1,"ik3o1"};	//57
			Dimension[ik3o2] = { 1,1,3,2,"ik3o2"};	//58
			Dimension[ik3o3] = { 1,1,3,3,"ik3o3"};	//59
			Dimension[ik3o4] = { 1,1,3,4,"ik3o4"};	//60
			Dimension[ik3o5] = { 1,1,3,5,"ik3o5"};	//61
			Dimension[ik3o6] = { 1,1,3,6,"ik3o6"};	//62
			Dimension[ik3o7] = { 1,1,3,7,"ik3o7"};	//63
		}
		dimension Dimension[64];
	};


	struct ball {
	public:
		void DrawSelf() {

		}

		void HandleCollision(ball& StruckBall, std::vector<ball>& balls, int& RoundsInWerfer, std::vector<ball>& rounds, int& nTargetBalls){//, std::vector<ball>& magazine) {
			int i, j, PointOfInsertion, QuestionType;
			float ClosestClamp = 1000;
			std::random_device rd; // obtain a random number from hardware
			std::mt19937 gen(rd()); // seed the generator
			std::uniform_int_distribution<> distrQType(1, 4);
			std::uniform_int_distribution<> distrQValues(1, 10); 
			//magazine.clear();
			if (nValue == StruckBall.nValue) {
				std::cout << "We have struck " << StruckBall.bbSum << std::endl;
				FreePosition.x = -100;
				StruckBall.FreePosition.x = -100;
				nTargetBalls--;
			}
			else {
				ball Wrong;
				ball OldRound;
				ball NewRound;
				//Clamp wrong answer
				for (i = 0; i < 8; i++)
					for (j = 0; j < 8; j++)
						if (sqrt((i * 32 - FreePosition.x) * (i * 32 - FreePosition.x) + (j * 32 - FreePosition.y) * (j * 32 - FreePosition.y)) < ClosestClamp) {
							ClosestClamp = sqrt((i * 32 - FreePosition.x) * (i * 32 - FreePosition.x) + (j * 32 - FreePosition.y) * (j * 32 - FreePosition.y));
							NewRound.ClampedPosition.x = i - 1;
							NewRound.ClampedPosition.y = j;
						}
				std::cout << "X " << Wrong.ClampedPosition.x << " Y" << Wrong.ClampedPosition.y << std::endl;
				//Generate new quesion
				QuestionType = (int)distrQType(gen);

				NewRound.FirstValue = (int)distrQValues(gen);
				NewRound.SecondValue = (int)distrQValues(gen);

				switch (QuestionType) {
				case Addition:
					NewRound.nValue = NewRound.FirstValue + NewRound.SecondValue;
					NewRound.bbSum = std::to_string(NewRound.FirstValue) + "+" + std::to_string(NewRound.SecondValue);
					break;
				case Subtraction:
					NewRound.nValue = NewRound.FirstValue - NewRound.SecondValue;
					NewRound.bbSum = std::to_string(NewRound.FirstValue) + "-" + std::to_string(NewRound.SecondValue);
					break;
				case Multiplication:
					NewRound.nValue = NewRound.FirstValue * NewRound.SecondValue;
					NewRound.bbSum = std::to_string(NewRound.FirstValue) + "x" + std::to_string(NewRound.SecondValue);
					break;
				case Division:
					NewRound.nValue = NewRound.FirstValue;
					NewRound.FirstValue = NewRound.FirstValue * NewRound.SecondValue;
					NewRound.bbSum = std::to_string(NewRound.FirstValue) + "/" + std::to_string(NewRound.SecondValue);
					break;
				}
				balls.push_back(NewRound);
				nTargetBalls++;
				
				//Remove Fired Round
				FreePosition.x = -100;
				//Reload Werfer with old round
				OldRound.nValue = nValue;
				//Find a random place to insert old round in Werfer
				if (RoundsInWerfer > 0) {
					std::uniform_int_distribution<> distrW(1, RoundsInWerfer); // define the range
					PointOfInsertion = (int)distrW(gen);
					if (PointOfInsertion != RoundsInWerfer) {
						rounds.insert(rounds.begin() + PointOfInsertion, OldRound);
						RoundsInWerfer++;
					} else {
						rounds.push_back(OldRound);
						RoundsInWerfer++;
					}
				} else {
					rounds.push_back(OldRound);
					RoundsInWerfer++;
				}
				//Find a random place to insert new round in Werfer
				if (RoundsInWerfer > 0) { //This should be redundant
					std::uniform_int_distribution<> distrW(1, RoundsInWerfer); // define the range
					PointOfInsertion = (int)distrW(gen);
					if (PointOfInsertion != RoundsInWerfer) {
						rounds.insert(rounds.begin() + PointOfInsertion, NewRound);
						RoundsInWerfer++;
					}
					else {
						rounds.push_back(NewRound);
						RoundsInWerfer++;
					}
				}
				else {
					rounds.push_back(NewRound);
					RoundsInWerfer++;
				}
			}
		}

		void HandleCollisionWithCeiling(std::vector<ball>& balls, int& RoundsInWerfer, std::vector<ball>& rounds, int& nTargetBalls) {
			int i, j, PointOfInsertion, QuestionType;
			float ClosestClamp = 1000;
			std::random_device rd; // obtain a random number from hardware
			std::mt19937 gen(rd()); // seed the generator
			std::uniform_int_distribution<> distrQType(1, 4);
			std::uniform_int_distribution<> distrQValues(1, 10);

			ball OldRound;
			ball NewRound;
			//Clamp wrong answer
			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					if (sqrt((i * 32 - FreePosition.x) * (i * 32 - FreePosition.x) + (j * 32 - FreePosition.y) * (j * 32 - FreePosition.y)) < ClosestClamp) {
						ClosestClamp = sqrt((i * 32 - FreePosition.x) * (i * 32 - FreePosition.x) + (j * 32 - FreePosition.y) * (j * 32 - FreePosition.y));
						NewRound.ClampedPosition.x = i - 1;
						NewRound.ClampedPosition.y = j;
					}
			//std::cout << "X " << Wrong.ClampedPosition.x << " Y" << Wrong.ClampedPosition.y << std::endl;
			//Generate new quesion

			NewRound.FreePosition.x = NewRound.ClampedPosition.x * 32;
			NewRound.FreePosition.y = 16;

			QuestionType = (int)distrQType(gen);

			NewRound.FirstValue = (int)distrQValues(gen);
			NewRound.SecondValue = (int)distrQValues(gen);

			switch (QuestionType) {
			case Addition:
				NewRound.nValue = NewRound.FirstValue + NewRound.SecondValue;
				NewRound.bbSum = std::to_string(NewRound.FirstValue) + "+" + std::to_string(NewRound.SecondValue);
				break;
			case Subtraction:
				NewRound.nValue = NewRound.FirstValue - NewRound.SecondValue;
				NewRound.bbSum = std::to_string(NewRound.FirstValue) + "-" + std::to_string(NewRound.SecondValue);
				break;
			case Multiplication:
				NewRound.nValue = NewRound.FirstValue * NewRound.SecondValue;
				NewRound.bbSum = std::to_string(NewRound.FirstValue) + "x" + std::to_string(NewRound.SecondValue);
				break;
			case Division:
				NewRound.nValue = NewRound.FirstValue;
				NewRound.FirstValue = NewRound.FirstValue * NewRound.SecondValue;
				NewRound.bbSum = std::to_string(NewRound.FirstValue) + "/" + std::to_string(NewRound.SecondValue);
				break;
			}
			balls.push_back(NewRound);
			nTargetBalls++;

			//Remove Fired Round
			FreePosition.x = -100;
			//Reload Werfer with old round
			OldRound.nValue = nValue;
			//Find a random place to insert old round in Werfer
			if (RoundsInWerfer > 0) {
				std::uniform_int_distribution<> distrW(1, RoundsInWerfer); // define the range
				PointOfInsertion = (int)distrW(gen);
				if (PointOfInsertion != RoundsInWerfer) {
					rounds.insert(rounds.begin() + PointOfInsertion, OldRound);
					RoundsInWerfer++;
				}
				else {
					rounds.push_back(OldRound);
					RoundsInWerfer++;
				}
			}
			else {
				rounds.push_back(OldRound);
				RoundsInWerfer++;
			}
			//Find a random place to insert new round in Werfer
			if (RoundsInWerfer > 0) { //This should be redundant
				std::uniform_int_distribution<> distrW(1, RoundsInWerfer); // define the range
				PointOfInsertion = (int)distrW(gen);
				if (PointOfInsertion != RoundsInWerfer) {
					rounds.insert(rounds.begin() + PointOfInsertion, NewRound);
					RoundsInWerfer++;
				}
				else {
					rounds.push_back(NewRound);
					RoundsInWerfer++;
				}
			}
			else {
				rounds.push_back(NewRound);
				RoundsInWerfer++;
			}
		}

		dimension ballDimension; //Looks like if the ball has no dimension it is a 'grabber'
		bool Minus;
		bool LeftMultiply;
		bool Clamped = false; //If ball clamped and lower than allowedn bottom value player dies
		bool InGun = false;
		bool Question;

		int nQUestionType;

		olc::vi2d ClampedPosition;
		olc::vf2d FreePosition = { 100,100 };
		olc::vf2d FreeVelocity;

		olc::vi2d PatchPositon;

		int FirstValue;
		int SecondValue;
		int nValue;
		std::string bbSum;
	};

	struct gun {
	public:
		void LoadGun() {
			//Swaps between rounds
		}
		void FireGun(std::vector<ball>& firedRounds, float fGunAngle) {
			//Deletes fired round from rounds
			if (rounds.size() > 0) {
				//rounds[chamberedRound].FreePosition.x = 128;
				//rounds[chamberedRound].FreePosition.y = 224;
				rounds[chamberedRound].FreeVelocity.x = 100 * cos(fGunAngle - Pi/2);
				rounds[chamberedRound].FreeVelocity.y = 100 * sin(fGunAngle - Pi/2);

				firedRounds.push_back(rounds[chamberedRound]);
				rounds.erase(rounds.begin() + chamberedRound);
				if(chamberedRound > 0)
					chamberedRound--;
				if(totalrounds > 0)
					totalrounds--;
			}
				//{
			//	auto i = remove_if(rounds.begin(), rounds.end(),
			//		[&](ball o) {return (;});
			//	if (i != rounds.end())
			//		rounds.erase(i, rounds.end());
			//}
		}

		float Pi = 3.1416f;
		bool loaded = false; // This may be redundant
		ball round;
		int chamberedRound =0;
		int totalrounds = 0;
		std::vector<ball> rounds;
	};

	struct QuestionGenerator {
	public:
		//void GenerateQuestion(ball& b, gun& Werfer, std::vector<ball>& magazine) {
		void GenerateQuestion(ball& b, std::vector<ball>& magazine) {
			std::random_device rd; // obtain a random number from hardware
			std::mt19937 gen(rd()); // seed the generator
			std::uniform_int_distribution<> distr(1, 10); // define the range

			b.FirstValue = (int)distr(gen);
			b.SecondValue = (int)distr(gen);

			switch (b.nQUestionType) {
			case Addition:
				b.nValue = b.FirstValue + b.SecondValue;
				b.bbSum = std::to_string(b.FirstValue) + "+" + std::to_string(b.SecondValue);
				break;
			case Subtraction:
				b.nValue = b.FirstValue - b.SecondValue; 
				b.bbSum = std::to_string(b.FirstValue) + "-" + std::to_string(b.SecondValue);
				break;
			case Multiplication:
				b.nValue = b.FirstValue * b.SecondValue;
				b.bbSum = std::to_string(b.FirstValue) + "x" + std::to_string(b.SecondValue);
				break;
			case Division:
				b.nValue = b.FirstValue;
				b.FirstValue = b.FirstValue * b.SecondValue;
				b.bbSum = std::to_string(b.FirstValue) + "/" + std::to_string(b.SecondValue);
				break;
			}
			//If I push this ball back onto a differnt vector? Is it the same ball or is it cloned? Lets find out
			magazine.push_back(b);
			//Werfer.totalrounds++;
		}
	};



	struct group {
	public:
		std::vector<ball> ballsInGroup;
	};

	struct groups {
	public:
		std::vector<group> groupsInRow;
	};

	

	//struct gunloader {
	//public:

		
	//};

	struct LevelRow {
		int Columns[8];
	};

	struct LevelMap {
		LevelRow Rows[8];
	};

	struct level {
	public:
		void LoadLevel(int nLevel, QuestionGenerator QuestionGen, gun& Werfer, std::vector<ball>& rounds, std::vector<ball>& magazine, std::vector<ball>& firedRounds, int& nTargetBalls) {
			int l, m;
			balls.clear();
			nTargetBalls = 0;
			firedRounds.clear();
			rounds.clear();
			magazine.clear();
			Werfer.totalrounds = 0;
			
			CurrentRow = 0;
			switch (nLevel) {
			case 1:
				initialNoLoadedRows = 1;
				secsForNewRow = 30;
				bbLevelMap.Rows[0] = { 0,1,0,1,0,1,0,1 };
				bbLevelMap.Rows[1] = { 0,0,0,0,0,0,0,0 }; //We are only going to take 7 of these
				bbLevelMap.Rows[2] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[3] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[4] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[5] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[6] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[7] = { 0,0,0,0,0,0,0,0 };
				break;
			case 2:
				initialNoLoadedRows = 2;
				secsForNewRow = 30;
				bbLevelMap.Rows[0] = { 0,1,0,3,0,1,0,3 };
				bbLevelMap.Rows[1] = { 0,0,3,0,1,0,0,0 }; //We are only going to take 7 of these
				bbLevelMap.Rows[2] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[3] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[4] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[5] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[6] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[7] = { 0,0,0,0,0,0,0,0 };
				break;
			case 3:
				initialNoLoadedRows = 2;
				secsForNewRow = 30;
				bbLevelMap.Rows[0] = { 0,4,0,3,0,0,1,0 };
				bbLevelMap.Rows[1] = { 0,0,1,0,0,3,0,4 }; //We are only going to take 7 of these
				bbLevelMap.Rows[2] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[3] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[4] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[5] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[6] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[7] = { 0,0,0,0,0,0,0,0 };
				break;
			case 4:
				initialNoLoadedRows = 3;
				secsForNewRow = 30;
				bbLevelMap.Rows[0] = { 0,0,0,1,3,0,0,0 }; 
				bbLevelMap.Rows[1] = { 0,1,0,3,0,1,0,0 }; //We are only going to take 7 of these
				bbLevelMap.Rows[2] = { 4,0,4,0,4,0,4,0 };
				
				bbLevelMap.Rows[3] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[4] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[5] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[6] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[7] = { 0,0,0,0,0,0,0,0 };
				break;
			case 100:
				bbLevelMap.Rows[0] = { 0,0,0,0,0,i,0,0 };
				bbLevelMap.Rows[1] = { 0,0,0,0,0,k2o2,0,0 }; //We are only going to take 7 of these
				bbLevelMap.Rows[2] = { 0,0,0,0,ik1,0,0,0 };
				bbLevelMap.Rows[3] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[4] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[5] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[6] = { 0,0,0,0,0,0,0,0 };
				bbLevelMap.Rows[7] = { 0,0,0,0,i,0,i,0 };
				break;
			}

			//This was extremely exciting only flawed... though we learned something
			for (l=0; l<initialNoLoadedRows; l++)
				for (m = 0; m < 8; m++) {
					//LevelData[l][m] = Dimensions.Dimension[bbLevelMap.Rows[l].Columns[m]];
					//if (LevelData[l][m].HasDimension == true) {
					//	bbBall.ballDimension = LevelData[l][m];
					if (bbLevelMap.Rows[l].Columns[m] != 0) {
						bbBall.nQUestionType = bbLevelMap.Rows[l].Columns[m];
						bbBall.Clamped = true;
						bbBall.ClampedPosition.x = m;
						bbBall.ClampedPosition.y = l;
						//bbBall.nValue = bbLevelMap.Rows[l].Columns[m];
						QuestionGen.GenerateQuestion(bbBall, magazine);
						balls.push_back(bbBall);
						nTargetBalls++;
					}
				}		//}

			std::random_device rd;
			std::mt19937 g(rd());

			std::shuffle(magazine.begin(), magazine.end(), g);

			for (ball b : magazine) {
				Werfer.rounds.push_back(b);
				Werfer.totalrounds++;
			}
		}

		void LoadRow(int nLevel, QuestionGenerator QuestionGen, gun& Werfer, std::vector<ball>& magazine, int& nTargetBalls) {
			int l, m;
			magazine.clear();
			switch (nLevel) {
			case 1:
				bbLevelMap.Rows[0] = { 1,0,1,0,1,0,1,0 };
				break;
			case 2:
				bbLevelMap.Rows[0] = { 3,0,1,0,3,0,1,0 };
				break;
			case 3:
				bbLevelMap.Rows[0] = { 4,0,1,0,3,0,1,0 };
				break;
			case 4:
				bbLevelMap.Rows[0] = { 1,3,0,1,3,4,1,0 };
				break;
			case 100:
				bbLevelMap.Rows[0] = { 0,0,0,0,0,i,0,0 };
				break;
			}

			for (ball& b : balls) {
				std::cout << ":" << b.ClampedPosition.y;
				b.ClampedPosition.y++;
				std::cout << ":" << b.ClampedPosition.y; 
			}

			for (m = 0; m < 8; m++) {
				if (bbLevelMap.Rows[CurrentRow].Columns[m] != 0) {
					bbBall.nQUestionType = bbLevelMap.Rows[CurrentRow].Columns[m];
					bbBall.Clamped = true;
					bbBall.ClampedPosition.x = m;
					bbBall.ClampedPosition.y = CurrentRow;
					QuestionGen.GenerateQuestion(bbBall, magazine);
					balls.push_back(bbBall);
					nTargetBalls++;
				}
			}		

			std::random_device rd;
			std::mt19937 g(rd());

			std::shuffle(magazine.begin(), magazine.end(), g);

			for (ball b : magazine) {
				Werfer.rounds.push_back(b);
				Werfer.totalrounds++;
			}
		}
		
		int initialNoLoadedRows;
		int secsForNewRow;
		int CurrentRow;
		
		ball bbBall;
		LevelMap bbLevelMap;
		dimension LevelData[8][8]; 
		DimensionVector Dimensions;
		std::vector<ball> balls;
		//QuestionGenerator QuestionGen;
				
		//, { 0,1,3,7 }
	}; //Right so first bool says whether there is a ball or not, then next three give
	// {										  //dimension
	

	//struct game {
	//public:


	//	std::vector<level> levels;
	//};

	olc::Sprite* Sun = nullptr;
	olc::Decal* SunDecal = nullptr;
	olc::Sprite* Sun2 = nullptr;
	olc::Decal* SunDecal2 = nullptr;
	olc::Sprite* SpriteSheet = nullptr;
	olc::Decal* SpriteSheetDecal = nullptr;

	float Pi = 3.142f;
	float RotationOffsets[100];
	float fOrbitx[4] = { 0,Pi/2,Pi, Pi*3/2 };
	float fOrbity[4] = { 0,Pi / 2,Pi, Pi * 3 / 2 };
	float fGunAngle = 0.0;
	float WTF = 0.0;
	float rotator = 0;

	int nMaxLevels = 4;
	int nCurrentLevel=1;
	level CurrentLevel;
	QuestionGenerator QuestionGen;

	int nTargetBalls = 0;

	std::chrono::steady_clock::time_point start;
	std::int32_t TimeInterval;

	gun Werfer;
	std::vector<ball> magazine;

	std::vector<ball> firedRounds;
	float DistanceToTarget;
	float ClosestDistanceToTarget;
	
	//int Pardon = 0;

	bool Paused = false;
//public:
	bool OnUserCreate() override
	{

		int i,j,k;
		CurrentLevel.LoadLevel(1, QuestionGen, Werfer, Werfer.rounds, magazine, firedRounds, nTargetBalls);


		Sun = new olc::Sprite("LogoSun11.png");
		SpriteMaskingLoader({ 0,0 }, Sun, { 0,0 }, { 270,270}, 1, 0);
		SunDecal = new olc::Decal(Sun, 1, 0);

		Sun2 = new olc::Sprite("LogoSun11.png");
		SunDecal2 = new olc::Decal(Sun2, 1, 0);

		SpriteSheet = new olc::Sprite("DimensionBlasterSpriteSheet.bmp");
		SpriteMaskingLoader({ 0,0 }, SpriteSheet, { 0,0 }, { 320,320 }, 1, 0);
		SpriteSheetDecal = new olc::Decal(SpriteSheet, 1, 0);
		// Called once at the start, so create things here

		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(1, 100); // define the range

		for (i = 0; i < 100; i++)
			RotationOffsets[i] = (float)distr(gen);

		//for (i = 0; i < 8; i++) {
		//	if ((i % 2) == 0) { k = 8; }
		//	else { k = 7; }
		//	for (j = 0;j < k;j++)
		//		std::cout << k << " ";
		//}

		//for(ball b: CurrentLevel.balls)
		//	std::cout << b.ballDimension.name.length();

		//Right so, check by line make groups, check each group is attached to a group above looks like the matrix is the winner
		//Once down check completed, check groups to see if they are attached to any group below them attached to a group above

		start = std::chrono::high_resolution_clock::now();
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		if (GetKey(olc::P).bPressed) Paused = !Paused;

		if (!Paused) {
			int i, j, k = 0;

			Clear(olc::BLACK);

			//Steer
			if (GetKey(olc::A).bHeld) if (fGunAngle > -1.3) { fGunAngle -= 3.5f * fElapsedTime; }
			else { fGunAngle = -1.3f; }
			if (GetKey(olc::D).bHeld) if (fGunAngle < 1.3) { fGunAngle += 3.5f * fElapsedTime; }
			else { fGunAngle = 1.3f; }

			//Load
			if (GetKey(olc::LEFT).bPressed) if (Werfer.chamberedRound < (Werfer.totalrounds-1)) { Werfer.chamberedRound++; std::cout << Werfer.chamberedRound << std::endl; }
			if (GetKey(olc::RIGHT).bPressed) if (Werfer.chamberedRound > 0) { Werfer.chamberedRound--; std::cout << Werfer.chamberedRound << std::endl; }

			//Fire
			if (GetKey(olc::UP).bPressed) Werfer.FireGun(firedRounds, fGunAngle);

			std::chrono::time_point<std::chrono::steady_clock> stop = std::chrono::high_resolution_clock::now();

			//auto duration = duration_cast<milliseconds>(stop - start);
			std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);;

			TimeInterval = (int32_t)duration.count();

			//DrawString(20, 200, "We have " + std::to_string(TimeInterval), olc::WHITE, 2);
			//std::cout << TimeInterval;

			//if (TimeInterval % (CurrentLevel.secsForNewRow) == 0) { Interesting
			if(TimeInterval > (CurrentLevel.secsForNewRow * 1000)){
				//Pardon++;
				start = std::chrono::high_resolution_clock::now();
				//std::cout << "Hit Cap'n" << (TimeInterval % (CurrentLevel.secsForNewRow)) << ":" << Pardon << std::endl;
				CurrentLevel.LoadRow(nCurrentLevel, QuestionGen, Werfer, magazine, nTargetBalls);
			}

			//Draw Gun
			DrawPartialRotatedDecal({ (256 / 2), 240 }, SpriteSheetDecal, fGunAngle, { 32,64 }, { 64,33 }, { 64,64 }, { 1,1 });
			//std::cout << fGunAngle << " Humpf" << WTF << " Pardon " << std::endl;

			//Draw Target Balls
			i = 0;
			for (ball b : CurrentLevel.balls) {
				i++;
				DrawPartialRotatedDecal({ (float)(32 + b.ClampedPosition.x * 32), (float)(16 + 32 * b.ClampedPosition.y) }, SpriteSheetDecal, RotationOffsets[i] += (fElapsedTime * 5), { 16,16 }, { 64,0 }, { 32,32 }, { 1,1 });
				//DrawStringDecal({ (float)(32 + b.ClampedPosition.x * 32), (float)(16 + 32 * b.ClampedPosition.y) }, std::to_string(b.nValue), olc::WHITE, { 1,1 });
				DrawStringDecal({ (float)(18 + b.ClampedPosition.x * 32), (float)(12 + 32 * b.ClampedPosition.y) }, b.bbSum, olc::BLUE, { 0.8f,0.8f });
				//Check for death
				if (b.ClampedPosition.y >= 6) {
					DrawString(20, 150, "Game Over", olc::WHITE, 2);;
					nCurrentLevel = 1;
					CurrentLevel.LoadLevel(nCurrentLevel, QuestionGen, Werfer, Werfer.rounds, magazine, firedRounds, nTargetBalls);
				}
			}

			//Draw Magazine
			i = 0;
			for (ball& b : Werfer.rounds) {
				//std::cout << "WTF" << std::endl;
				if (i != Werfer.chamberedRound) {
					DrawPartialRotatedDecal({ (float)(128 - (32 * Werfer.chamberedRound) + 32 * i), (float)240 }, SpriteSheetDecal, RotationOffsets[i] += (fElapsedTime * 5), { 16,16 }, { 64,0 }, { 32,32 }, { 1,1 });
					DrawStringDecal({ (float)(120 - (32 * Werfer.chamberedRound) + 32 * i), (float)238 }, std::to_string(b.nValue), olc::BLUE, { 0.8f,0.8f });
				}
				else {
					b.FreePosition.x = (float)(128 + (16 * sin(fGunAngle)));
					b.FreePosition.y = (float)(240 - (16 * cos(fGunAngle)));
					DrawPartialRotatedDecal({ (float)(128 - (32 * Werfer.chamberedRound) + 32 * i + (16 * sin(fGunAngle))), (float)(240 - (16 * cos(fGunAngle)))}, SpriteSheetDecal, RotationOffsets[i] += (fElapsedTime * 5), { 16,16 }, { 64,0 }, { 32,32 }, { 1,1 });
					DrawStringDecal({ (float)(120 - (32 * Werfer.chamberedRound) + 32 * i + (16 * sin(fGunAngle))), (float)(238 - (16 * cos(fGunAngle))) }, std::to_string(b.nValue), olc::BLUE, { 0.8f,0.8f });
				}
				i++;
			}

			for (ball& b : firedRounds) {
				b.FreePosition += b.FreeVelocity * fElapsedTime;
				DrawPartialRotatedDecal(b.FreePosition, SpriteSheetDecal, 0, { 16,16 }, { 64,0 }, { 32,32 }, { 1,1 });
				DrawStringDecal({ b.FreePosition.x - 10, b.FreePosition.y }, std::to_string(b.nValue), olc::BLUE, { 1,1 });
				//ClosestDistanceToTarget = 1000;
				for (ball& Target : CurrentLevel.balls) {
					DistanceToTarget = sqrt((((32+Target.ClampedPosition.x *32))- b.FreePosition.x) * ((32+(Target.ClampedPosition.x*32))- b.FreePosition.x) + (((16+Target.ClampedPosition.y*32)) - b.FreePosition.y)*(((16+Target.ClampedPosition.y *32)) - b.FreePosition.y));
					if (DistanceToTarget < 32) {
						b.HandleCollision(Target, CurrentLevel.balls, Werfer.totalrounds, Werfer.rounds, nTargetBalls);
					}
				}
				//Handle Collison with wall
				if ((b.FreePosition.x <= 32) || (b.FreePosition.x >= 240))
					b.FreeVelocity.x = b.FreeVelocity.x * -1;
				//Handle Collison with Ceiling
				if (b.FreePosition.y < 0)
					b.HandleCollisionWithCeiling(CurrentLevel.balls, Werfer.totalrounds, Werfer.rounds, nTargetBalls);
			}

			//Tidy up offscreen balls
			if (CurrentLevel.balls.size() > 0)
			{
				auto i = remove_if(CurrentLevel.balls.begin(), CurrentLevel.balls.end(),
					[&](ball b) {return (b.FreePosition.x < -50);});
				if (i != CurrentLevel.balls.end()) {
					CurrentLevel.balls.erase(i, CurrentLevel.balls.end());
					std::cout << "Ball erased" << std::endl;
				}
			}

			//Tidy up offscree fired rounds
			if (firedRounds.size() > 0)
			{
				auto i = remove_if(firedRounds.begin(), firedRounds.end(),
					[&](ball b) {return (b.FreePosition.x < -50);});
				if (i != firedRounds.end()){
					firedRounds.erase(i, firedRounds.end());
					std::cout << "Round erased" << std::endl;
				}
			}
			//Check for Victory
			if (nTargetBalls != 0) {
				//DrawString(20, 150, std::to_string(nTargetBalls) + " : Balls", olc::WHITE, 2);
			} else {
				//DrawString(20, 150, "Victory", olc::WHITE, 2);
				if (nCurrentLevel < nMaxLevels) {
					nCurrentLevel++;
				} else {
					nCurrentLevel = 1;
				}
				CurrentLevel.LoadLevel(nCurrentLevel, QuestionGen, Werfer, Werfer.rounds, magazine, firedRounds, nTargetBalls);
				start = std::chrono::high_resolution_clock::now();
			}
		}

		return true;
	}

	

	void SpriteMaskingLoader(const olc::vi2d& pos, olc::Sprite* sprite, const olc::vi2d& sourcepos, const olc::vi2d& size, uint32_t scale, uint8_t flip)
	{
		SpriteMasking(pos.x, pos.y, sprite, sourcepos.x, sourcepos.y, size.x, size.y, scale, flip);
	}


	void SpriteMasking(int32_t x, int32_t y, olc::Sprite* sprite, int32_t ox, int32_t oy, int32_t w, int32_t h, uint32_t scale, uint8_t flip)
	{
		if (sprite == nullptr)
			return;

		int32_t fxs = 0, fxm = 1, fx = 0;
		int32_t fys = 0, fym = 1, fy = 0;
		if (flip & olc::Sprite::Flip::HORIZ) { fxs = w - 1; fxm = -1; }
		if (flip & olc::Sprite::Flip::VERT) { fys = h - 1; fym = -1; }

		//if (scale > 1)
		//{
		//	fx = fxs;
		//	for (int32_t i = 0; i < w; i++, fx += fxm)
		//	{
		//		fy = fys;
		//		for (int32_t j = 0; j < h; j++, fy += fym)
		//			for (uint32_t is = 0; is < scale; is++)
		//				for (uint32_t js = 0; js < scale; js++)
		//					Draw(x + (i * scale) + is, y + (j * scale) + js, sprite->GetPixel(fx + ox, fy + oy));
		//	}
		//}
		//else
		//{
		fx = fxs;
		for (int32_t i = 0; i < w; i++, fx += fxm){
			fy = fys;
			for (int32_t j = 0; j < h; j++, fy += fym)
				if (sprite->GetPixel(fx + ox, fy + oy).b == 255)
					sprite->SetPixel({ fx + ox, fy + oy }, olc::Pixel::MASK);
						//Draw(x + i, y + j, sprite->GetPixel(fx + ox, fy + oy));
		}
		//}
	}
};



int main()
{
	DimensionBlaster demo;
	if (demo.Construct(286, 256, 2, 2))
		demo.Start();

	return 0;
}

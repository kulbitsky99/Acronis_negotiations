#include <string>   //
#include <iostream> //
#include <assert.h>


enum COMPONENTS
{
	FIELD_SIZE = 9,
	LINE_SIZE  = 3,
	POS_AMOUNT = 19683
};

enum FIELDS
{
	ZERO  = 0,
	CROSS = 1,
	EMPTY = 2
};

class Pos
{
public:
	Pos();
	Pos(char* field);
	~Pos();
	const char * getPos() const;
	void setPos(char* field);
	bool isWinner(const int flag);
	bool isWinnerX();
	bool isWinnerO();
	const int number(const int flag) const;
	const int numberX() const;
	const int numberO() const;
private:
	char * field_;
};

void lookup(Pos & pos);

int main()
{
	Pos pos = {};
	lookup(pos);
}

void lookup(Pos & pos)
{
	int i = 0;
	int valid(0);
	for(char i1(0); i1 < LINE_SIZE; ++i1)
		for(char i2(0); i2 < LINE_SIZE; ++i2)
			for(char i3(0); i3 < LINE_SIZE; ++i3)
				for(char i4(0); i4 < LINE_SIZE; ++i4)
					for(char i5(0); i5 < LINE_SIZE; ++i5)
						for(char i6(0); i6 < LINE_SIZE; ++i6)
							for(char i7(0); i7 < LINE_SIZE; ++i7)
								for(char i8(0); i8 < LINE_SIZE; ++i8)
									for(char i9(0); i9 < LINE_SIZE; ++i9)
									{
										char c[9] = {i1, i2, i3, i4, i5, i6, i7, i8, i9};
										pos.setPos(c);
										int nx = pos.numberX();
										int no = pos.numberO();


										/*
										if((((nx + no) == 6) || ((nx + no) == 8)) && (nx == no))
										{
											valid++;
										}
										if((((nx + no) == 5) || ((nx + no) == 7)) && (nx == no + 1))
										{
											valid++;
										}
										*/
										if(nx + no < 5)
										{
											if( (nx == 0) && (no == 0))
												valid++;
											if( (nx == 1) && (no == 0))
												valid++;
											if( (nx == 1) && (no == 1))
												valid++;
											if( (nx == 2) && (no == 1))
												valid++;
											if( (nx == 2) && (no == 2))
												valid++;
										}

										if((nx == no) && (nx + no == 6) && (pos.isWinnerX() == false) && (pos.isWinnerO() == true))
										{
											valid++;
										}
										if((nx == no) && (nx + no == 6) && (pos.isWinnerX() == false) && (pos.isWinnerO() == false))
										{
											valid++;
										}

										if((nx == no) && (nx + no == 8) && (pos.isWinnerX() == false) && (pos.isWinnerO() == true))
										{
											valid++;
										}

										if((nx == no) && (nx + no == 8) && (pos.isWinnerX() == false) && (pos.isWinnerO() == false))
										{
											valid++;
										}

										if((nx == no + 1) && (nx + no == 5) && (pos.isWinnerX() == true) && (pos.isWinnerO() == false))
										{
											valid++;
										}

										if((nx == no + 1) && (nx + no == 5) && (pos.isWinnerX() == false) && (pos.isWinnerO() == false))
										{
											valid++;
										}
										
										if((nx == no + 1) && (nx + no == 7) && (pos.isWinnerX() == true) && (pos.isWinnerO() == false))
										{
											valid++;
										}

										if((nx == no + 1) && (nx + no == 7) && (pos.isWinnerX() == false) && (pos.isWinnerO() == false))
										{
											valid++;
										}
										
										if((nx == no + 1) && (nx + no == 9) && (pos.isWinnerX() == true) && (pos.isWinnerO() == false))
										{
											valid++;
										}


										i++;
									}
	std::cout << "i = " << i << " valid = " << valid << std::endl;

}

const int Pos::numberX() const{
	return this->number(CROSS);
}


const int Pos::numberO() const{
	return this->number(ZERO);
}

const int Pos::number(const int flag) const{
	int number(0);
	for(int i(0); i < FIELD_SIZE; ++i)
	{
		if(field_[i] == flag)
			number++;
	}
	return number;
}

bool Pos::isWinnerX()
{
	return this->isWinner(CROSS);
}


bool Pos::isWinnerO()
{
	return this->isWinner(ZERO);
}

bool Pos::isWinner(const int flag)
{
	bool isWinner = true;
	int number_of_won_combinations(0);

	// strings
	for(int j(0); j < LINE_SIZE; ++j)
	{
		isWinner = true;
		for(int i(j*LINE_SIZE); i < j*LINE_SIZE + LINE_SIZE; ++i)
		{
			if(field_[i] != flag)
			{
				isWinner = false;
				break;
			}
		}
		if(isWinner == true)
			number_of_won_combinations++; // 1
	}
	// 

	for(int j(0); j < LINE_SIZE; ++j)
	{
		isWinner = true;
		for(int i(j); i < FIELD_SIZE; i += LINE_SIZE)
		{
			if(field_[i] != flag)
			{
				isWinner = false;
				break;
			}
		}
		if(isWinner == true)
			number_of_won_combinations++; // 1 or 2 (2 is invalid variant)
	}

	if((field_[0] == field_[4]) && (field_[4] == field_[8]) && (field_[8] == flag))
		number_of_won_combinations++;
	if((field_[2] == field_[4]) && (field_[4] == field_[6]) && (field_[6] == flag))
		number_of_won_combinations++;


	// if(field_[0] == field_[3] == field_[6])

	if((number_of_won_combinations == 1))
		return true;
	else
		return false;
}


Pos::Pos():
	field_(new char[FIELD_SIZE])
{
	for(int i(0); i < FIELD_SIZE; ++i)
	{
		field_[i] = EMPTY;
	}
};

Pos::Pos(char* field)
{
	field_ = field;
}

Pos::~Pos()
{
	delete field_;
}

const char * Pos::getPos() const
{
	return field_;
}

void Pos::setPos(char* field)
{
	assert(field);
	for(int i(0); i < FIELD_SIZE; ++i)
	{
		field_[i] = field[i];
	}

}






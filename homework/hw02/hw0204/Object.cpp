#include "Splash.h"
#include "Object.h"
#include<cmath>
#include<stack>
int Object::act_water(Direction fromwhere, Actor fromwho) {
	// TODO
	int a_score = 0;
	if(fromwho == WATER || fromwho == PLAYER) {
		if(this->size < 3) {
			this->size++;
			return a_score;
		}
		else {
			set2void(x, y, this->splash);
			a_score++;
			//cout << "(x, y) = "<< x << y <<" + 1" << endl;
			if(x > 0) {
				//cout << "in x > 0" << endl;
				int i = x - 1, j = y;
				Object* obj = this->splash->map[i][j];
				if(obj->type == T_BARRIER) {
					a_score += obj->act_barrier(NONE, WATER);
				}
				else if(obj->type == T_VOID) {
					a_score += obj->act_void(UP, WATER);
				}
				else if(obj->type == T_WATER) {
					a_score += obj->act_water(NONE, WATER);
				}
				else {
					a_score += obj->act_toxic(NONE, WATER);
				}
			}
			if(y > 0) {
				//cout << "in y > 0" << endl;
				int i = x, j = y - 1;
				Object* obj = this->splash->map[i][j];
				if(obj->type == T_BARRIER) {
					a_score += obj->act_barrier(NONE, WATER);
				}
				else if(obj->type == T_VOID) {
					a_score += obj->act_void(LEFT, WATER);
				}
				else if(obj->type == T_WATER) {
					a_score += obj->act_water(NONE, WATER);
				}
				else {
					a_score += obj->act_toxic(NONE, WATER);
				}
			}
			if(x < this->splash->size - 1) {
				//cout << "in x < n - 1" << endl;
				int i = x + 1, j = y;
				Object* obj = this->splash->map[i][j];
				if(obj->type == T_BARRIER) {
					a_score += obj->act_barrier(NONE, WATER);
				}
				else if(obj->type == T_VOID) {
					a_score += obj->act_void(DOWN, WATER);
				}
				else if(obj->type == T_WATER) {
					a_score += obj->act_water(NONE, WATER);
				}
				else {
					a_score += obj->act_toxic(NONE, WATER);
				}
			}
			if(y < this->splash->size - 1) {
				//cout << "in y < n - 1" << endl;
				int i = x, j = y + 1;
				Object* obj = this->splash->map[i][j];
				if(obj->type == T_BARRIER) {
					a_score += obj->act_barrier(NONE, WATER);
				}
				else if(obj->type == T_VOID) {
					a_score += obj->act_void(RIGHT, WATER);
				}
				else if(obj->type == T_WATER) {
					a_score += obj->act_water(NONE, WATER);
				}
				else {
					a_score += obj->act_toxic(NONE, WATER);
				}
			}
			//delete this;
		}
	}
	if(fromwho == TOXIC) {
		if(this->size == 1) {
			set2void(x, y, this->splash);
			//delete this;
		}
		else {
			this->size--;
		}
	}
	return a_score;
}

int Object::act_void(Direction fromwhere, Actor fromwho) {
	// TODO
	int a_score = 0;
	if(fromwho == PLAYER)
		cout << "Error: Cannot act a Void." << endl;
	else if(fromwho == WATER) {
		if(fromwhere == UP) {
			if(x == 0) return a_score;
			else {
				Object* obj = this->splash->map[x - 1][y];
				switch(obj->type) {
					case T_WATER:
						a_score += obj->act_water(NONE, WATER);
						break;
					case T_TOXIC:
						a_score += obj->act_toxic(NONE, WATER);
						break;
					case T_VOID:
						a_score += obj->act_void(UP, WATER);
						break;
					case T_BARRIER:
						a_score += obj->act_barrier(NONE, WATER);
						break;
					default:
						break;
				}
			}
		}
		if(fromwhere == DOWN) {
			if(x == this->splash->size - 1) return a_score;
			else {
				Object* obj = this->splash->map[x + 1][y];
				switch(obj->type) {
					case T_WATER:
						a_score += obj->act_water(NONE, WATER);
						break;
					case T_TOXIC:
						a_score += obj->act_toxic(NONE, WATER);
						break;
					case T_VOID:
						a_score += obj->act_void(DOWN, WATER);
						break;
					case T_BARRIER:
						a_score += obj->act_barrier(NONE, WATER);
						break;
					default:
						break;
				}
			}
		}
		if(fromwhere == RIGHT) {
			if(y == this->splash->size - 1) return a_score;
			else {
				Object* obj = this->splash->map[x][y + 1];
				switch(obj->type) {
					case T_WATER:
						a_score += obj->act_water(NONE, WATER);
						break;
					case T_TOXIC:
						a_score += obj->act_toxic(NONE, WATER);
						break;
					case T_VOID:
						a_score += obj->act_void(RIGHT, WATER);
						break;
					case T_BARRIER:
						a_score += obj->act_barrier(NONE, WATER);
						break;
					default:
						break;
				}
			}
		}
		if(fromwhere == LEFT) {
			if(y == 0) return a_score;
			else {
				Object* obj = this->splash->map[x][y - 1];
				switch(obj->type) {
					case T_WATER:
						a_score += obj->act_water(NONE, WATER);
						break;
					case T_TOXIC:
						a_score += obj->act_toxic(NONE, WATER);
						break;
					case T_VOID:
						a_score += obj->act_void(LEFT, WATER);
						break;
					case T_BARRIER:
						a_score += obj->act_barrier(NONE, WATER);
						break;
					default:
						break;
				}
			}
		}
	}
	else {
		if(fromwhere == UP) {
			if(x == 0) return a_score;
			else {
				Object* obj = this->splash->map[x - 1][y];
				switch(obj->type) {
					case T_WATER:
						a_score += obj->act_water(NONE, TOXIC);
						break;
					case T_TOXIC:
						a_score += obj->act_toxic(NONE, TOXIC);
						break;
					case T_VOID:
						a_score += obj->act_void(UP, TOXIC);
						break;
					case T_BARRIER:
						a_score += obj->act_barrier(NONE, TOXIC);
						break;
					default:
						break;
				}
			}
		}
		if(fromwhere == DOWN) {
			if(x == this->splash->size - 1) return a_score;
			else {
				Object* obj = this->splash->map[x + 1][y];
				switch(obj->type) {
					case T_WATER:
						a_score += obj->act_water(NONE, TOXIC);
						break;
					case T_TOXIC:
						a_score += obj->act_toxic(NONE, TOXIC);
						break;
					case T_VOID:
						a_score += obj->act_void(DOWN, TOXIC);
						break;
					case T_BARRIER:
						a_score += obj->act_barrier(NONE, TOXIC);
						break;
					default:
						break;
				}
			}
		}
		if(fromwhere == RIGHT) {
			if(y == this->splash->size - 1) return a_score;
			else {
				Object* obj = this->splash->map[x][y + 1];
				switch(obj->type) {
					case T_WATER:
						a_score += obj->act_water(NONE, TOXIC);
						break;
					case T_TOXIC:
						a_score += obj->act_toxic(NONE, TOXIC);
						break;
					case T_VOID:
						a_score += obj->act_void(RIGHT, TOXIC);
						break;
					case T_BARRIER:
						a_score += obj->act_barrier(NONE, TOXIC);
						break;
					default:
						break;
				}
			}
		}
		if(fromwhere == LEFT) {
			if(y == 0) return a_score;
			else {
				Object* obj = this->splash->map[x][y - 1];
				switch(obj->type) {
					case T_WATER:
						a_score += obj->act_water(NONE, TOXIC);
						break;
					case T_TOXIC:
						a_score += obj->act_toxic(NONE, TOXIC);
						break;
					case T_VOID:
						a_score += obj->act_void(LEFT, TOXIC);
						break;
					case T_BARRIER:
						a_score += obj->act_barrier(NONE, TOXIC);
						break;
					default:
						break;
				}
			}
		}
	}
	return a_score;
}

int Object::act_barrier(Direction fromwhere, Actor fromwho) {
	// TODO
	int a_score = 0;
	if(fromwho == PLAYER)
		cout << "Error: Cannot act a Barrier." << endl;
	// else 
	// 	cout << "meet barrier" << endl;
	return a_score;
}

int Object::act_toxic(Direction fromwhere, Actor fromwho) {
	// TODO
	int a_score = 0;
	if(fromwho == TOXIC || fromwho == PLAYER) {
		if(this->size < 3) {
			this->size++;
			return a_score;
		}
		else {
			set2void(x, y, this->splash);
			a_score--;
			//cout << "(x, y) = "<< x << y << "- 1" << endl;
			if(x > 0) {
				int i = x - 1, j = y;
				Object* obj = this->splash->map[i][j];
				if(obj->type == T_BARRIER) {
					a_score += obj->act_barrier(NONE, TOXIC);
				}
				else if(obj->type == T_VOID) {
					a_score += obj->act_void(UP, TOXIC);
				}
				else if(obj->type == T_WATER) {
					a_score += obj->act_water(NONE, TOXIC);
				}
				else {
					a_score += obj->act_toxic(NONE, TOXIC);
				}
			}
			if(y > 0) {
				int i = x, j = y - 1;
				Object* obj = this->splash->map[i][j];
				if(obj->type == T_BARRIER) {
					a_score += obj->act_barrier(NONE, TOXIC);
				}
				else if(obj->type == T_VOID) {
					a_score += obj->act_void(LEFT, TOXIC);
				}
				else if(obj->type == T_WATER) {
					a_score += obj->act_water(NONE, TOXIC);
				}
				else {
					a_score += obj->act_toxic(NONE, TOXIC);
				}
			}
			if(x < this->splash->size - 1) {
				int i = x + 1, j = y;
				Object* obj = this->splash->map[i][j];
				if(obj->type == T_BARRIER) {
					a_score += obj->act_barrier(NONE, TOXIC);
				}
				else if(obj->type == T_VOID) {
					a_score += obj->act_void(DOWN, TOXIC);
				}
				else if(obj->type == T_WATER) {
					a_score += obj->act_water(NONE, TOXIC);
				}
				else {
					a_score += obj->act_toxic(NONE, TOXIC);
				}
			}
			if(y < this->splash->size - 1) {
				int i = x, j = y + 1;
				Object* obj = this->splash->map[i][j];
				if(obj->type == T_BARRIER) {
					a_score += obj->act_barrier(NONE, TOXIC);
				}
				else if(obj->type == T_VOID) {
					a_score += obj->act_void(RIGHT, TOXIC);
				}
				else if(obj->type == T_WATER) {
					a_score += obj->act_water(NONE, TOXIC);
				}
				else {
					a_score += obj->act_toxic(NONE, TOXIC);
				}
			}
			//delete this;
		}
		
	}
	if(fromwho == WATER) {
		if(this->size == 1) {
			set2void(x, y, this->splash);
			//delete this;
		}
		else {
			this->size--;
		}
	}
	return a_score;
}
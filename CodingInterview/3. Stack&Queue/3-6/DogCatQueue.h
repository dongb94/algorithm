#include <iostream>
#include <queue>

class Animal {
public:
	int num;
	Animal(int n) { num = n; }
};
class Dog : public Animal { 
public : 
	Dog(int n) : Animal(n) {}
};
class Cat : public Animal {
public:
	Cat(int n) : Animal(n) {}
};

class DogCatQueue{
private:
	std::queue<Dog> dogQueue;
	std::queue<Cat> catQueue;
	std::queue<bool> indexQueue;
	int catCnt;
	int dogCnt;
public:
	DogCatQueue() {
		catCnt = 0;
		dogCnt = 0;
	}

	void enqueue(Cat type) {
		catQueue.push(type);
		indexQueue.push(false);
	}

	void enqueue(Dog type) {
		dogQueue.push(type);
		indexQueue.push(true);
	}

	Animal dequeueAny() {
		bool out = indexQueue.front();

		if (out) {
			return dequeueDog();
		} else {
			return dequeueCat();
		}
		return out;
	}

	Cat dequeueCat() {
		Cat out = catQueue.front();
		catQueue.pop();

		if (!indexQueue.front())
			indexQueue.pop();
		else
			catCnt++;

		while (dogCnt != 0 && indexQueue.front()) {
			indexQueue.pop();
			dogCnt--;
		}

		return out;
	}

	Dog dequeueDog() {
		Dog out = dogQueue.front();
		dogQueue.pop();

		if (indexQueue.front())
			indexQueue.pop();
		else
			dogCnt++;

		while (catCnt != 0 && !indexQueue.front()) {
			indexQueue.pop();
			catCnt--;
		}

		return out;
	}
};
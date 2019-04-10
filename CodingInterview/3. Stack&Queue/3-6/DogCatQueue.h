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
	std::queue<Animal> indexQueue;
	int catCnt;
	int dogCnt;
public:
	DogCatQueue() {
		catCnt = 0;
		dogCnt = 0;
	}

	void enqueue(Cat type) {
		catQueue.push(type);
		indexQueue.push(type);
	}

	void enqueue(Dog type) {
		dogQueue.push(type);
		indexQueue.push(type);
	}

	Animal dequeueAny() {
		Animal out = indexQueue.front();

		if (typeid(out) == typeid(Cat)) {
			return dequeueCat();
		}else if (typeid(out) == typeid(Cat)) {
			return dequeueDog();
		}
		return out;
	}

	Cat dequeueCat() {
		Cat out = catQueue.front();
		catQueue.pop();

		if (typeid(indexQueue.front()) == typeid(Cat))
			indexQueue.pop();
		else
			catCnt++;

		while (dogCnt != 0 && typeid(indexQueue.front()) == typeid(Dog)) {
			indexQueue.pop();
			dogCnt--;
		}

		return out;
	}

	Dog dequeueDog() {
		Dog out = dogQueue.front();
		dogQueue.pop();

		if (typeid(indexQueue.front()) == typeid(Dog))
			indexQueue.pop();
		else
			dogCnt++;

		while (catCnt != 0 && typeid(indexQueue.front()) == typeid(Cat)) {
			indexQueue.pop();
			catCnt--;
		}

		return out;
	}
};
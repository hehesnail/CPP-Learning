#include <iostream>

using namespace std;

enum imageType
{
	LSAT, SPOT
};

class Image
{
public:
	virtual void draw() = 0;
	static Image* findAndClone(imageType);
protected:
	virtual imageType returnType() = 0;
	virtual Image* clone() = 0;
	static void addPrototype(Image* image)
	{
		_prototypes[_nextSlot++] = image;
	}
private:
	static Image* _prototypes[10];
	static int _nextSlot;
};
Image* Image::_prototypes[];
int Image::_nextSlot;

Image* Image::findAndClone(imageType type)
{
	for(size_t i = 0; i != _nextSlot; i++)
	{
		if (_prototypes[i]->returnType() == type)
		{
			return _prototypes[i]->clone();
		}
	}
}

class LandSatImage: public Image
{
public:
	imageType returnType()
	{
		return LSAT;
	}

	void draw() 
	{
		cout << "LandSatImage::draw " << _id << endl;
	}

	Image* clone()
	{
		return new LandSatImage(1);
	}
protected:
	LandSatImage(int dummy)
	{
		_id = _count++;
	}

private:	
	static LandSatImage _landSatImage;
	LandSatImage()
	{
		addPrototype(this);
	}
	int _id;
	static int _count;
};

LandSatImage LandSatImage::_landSatImage;
int LandSatImage::_count = 1;

class SpotImage: public Image
{
public:
	imageType returnType()
	{
		return SPOT;
	}
	void draw()
	{
		cout << "SpotImage::draw " << _id << endl;
	}

	Image* clone()
	{
		return new SpotImage(1);
	}
protected:
	SpotImage(int dummy)
	{
		_id = _count++;
	}

private:
	SpotImage()
	{
		addPrototype(this);
	}
	static SpotImage _spotImage;
	int _id;
	static int _count;
};

SpotImage SpotImage::_spotImage;
int SpotImage::_count = 1;

const int NUM_IMAGES = 8;
imageType input[NUM_IMAGES] = 
{
	LSAT, LSAT, LSAT, SPOT, LSAT, SPOT, SPOT, LSAT
};

int main()
{
	Image* images[NUM_IMAGES];
	for (int i = 0; i < NUM_IMAGES; i++)
		images[i] = Image::findAndClone(input[i]);
	for (int i = 0; i < NUM_IMAGES; i++)
		images[i]->draw();
	for (int i = 0; i < NUM_IMAGES; i++)
		delete images[i];

	return 0;
}


#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;

	// Where is the player
	Vector2f m_Position;
	// The sprite
	Sprite m_Sprite;
	// The texture
	Texture m_Texture;
	// The screen resolution
	Vector2f m_Resolution;
	// Size of the arena
	IntRect m_Arena;
	// The size of each tile in the arena
	int m_TileSize;
	// Player direction
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;
	// Player health
	int m_Health;
	// Player's maximum health
	int m_MaxHealth;
	// Last time player was hit
	Time m_LastHit;
	// Speed in pixels per second
	float m_Speed;

public:
	Player();
	void spawn(IntRect arena, Vector2f resolution, int tileSize);
	// Call this at the end of every game
	void resetPlayerStats();

	// Handle the player getting hit by a zombie
	bool hit(Time timeHit);
	// How long ago was the player last hit
	Time getLastHitTime();
	// Where is the player
	FloatRect getPosition();
	// Where is the center of the player
	Vector2f getCenter();
	// What angle is the player facing
	float getRotation();
	// Send a copy of the sprite to the main function
	Sprite getSprite();
	// The player move functions
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	// Stop the player moving in a specific direction
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	// Call this function once every frame
	void update(float elapsedTime, Vector2i mousePosition);
	// Give the player a speed boost
	void upgradeSpeed();
	// Give the player some health
	void upgradeHealth();
	// Increase the maximum amount of health the player can have
	void increaseHealthLevel(int amount);
	// How much health has the player currently got
	int getHealth();
};
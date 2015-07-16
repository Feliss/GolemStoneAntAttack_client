# Golem Stone: Ant Attack

This repository stands for game client written in C++ for Unreal Engine 4
You can review Node.js server code in the following repository: https://github.com/Fleischers/GolemStoneAntAttack_server

## Installation and setup

To install and launch application you will need Unreal Engine 4

## TCP API

### Client to server:

```
CONNECT|NICKNAME
LOCATION|X|Y|Z
MOVE|X|Y|Z|SPEED|ACCELERATION
STOP|X|Y|Z
PICK
THROW|X|Y|Z|SPEED|ACCELERATION
HIT|PLAYER_ID
DEATH
DISCONNECT
```

### Server to client:

```
CONNECTED|PLAYER_ID
PLAYER_ID|CONNECTED|NICKNAME
PLAYER_ID|LOCATION|X|Y|Z
PLAYER_ID|MOVE|X|Y|Z|SPEED|ACCELERATION
PLAYER_ID|STOP|X|Y|Z
PLAYER_ID|PICK
PLAYER_ID|THROW|X|Y|Z|SPEED|ACCELERATION
PLAYER_ID|HIT
PLAYER_ID|DEATH
PLAYER_ID|REVIVE
PLAYER_ID|DISCONNECT
```

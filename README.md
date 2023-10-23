# Structural Design Patterns

## Author: Balan Artiom

----

## Objectives:

* Get familiar with the Design Patterns;
* Choose a specific domain;
* Implement at least 2 CDPs for the specific domain; 


## Used Design Patterns: 

* Adapter pattern


## Implementation

For the **adapter pattern**, pretend there is a legacy library called `legacySocket`,
but our client needs a Target that implements the `SocketInterface`.
To solve this, we write an adapter called `LegacySocketAdapter`
which uses a `LegacySocket` object and basically renames the methods by wrapping around them.

Thus, the client can use a `LegacySocket` without being concerned with  its old legacy interface,
and as if `LegacySocket` implemented its new fashionable `SocketInterface`:

``` c++
// legacy library
class LegacySocket {
public:
    void connectLegacy();
    void sendDataLegacy();
};

...

// interface required by client 
class SocketInterface {
public:
    virtual void connect() = 0;
    virtual void sendData() = 0;
};

...

// client code
LegacySocketAdapter adapter(new LegacySocket);
adapter.connect();
adapter.sendData();
```



## Conclusions / Screenshots / Results

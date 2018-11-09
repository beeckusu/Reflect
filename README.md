# Reflect

Currently only tested on OSX.

## Install

You'll need to install pip, Python 2.6 or greater.
In addition, run the following commands:

```
pip install --upgrade google-api-python-client

pip install --upgrade google-auth google-auth-oauthlib google-auth-httplib2

pip install --upgrade requests

pip install --upgrade oauth2client
```

You'll also need the libcurl and libjson libraries with the following commands:

OSX:
```
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" < /dev/null 2> /dev/null
brew install curl
brew install jsoncpp
```

Unix:
```
sudo apt-get install libjsoncpp-dev
sudo ln -s /usr/include/jsoncpp/json/ /usr/include/json
sudo apt-get install libcurl4-openssl-dev
```

## Testing

```
g++ -std=c++11 main.cpp mirror.cpp time.cpp calendar.cpp event.cpp weather.cpp module.cpp  -ljsoncpp -lcurl -o reflect.out

g++ -std=c++11 event.cpp calendar.cpp calendartest.cpp

./reflect.out
```
Console should output the date, time, weather, and some calendar information.

```
g++ -std=c++11 event.cpp calendar.cpp calendartest.cpp calendartest

./calendartest
```

use for testing calendar module
## Running

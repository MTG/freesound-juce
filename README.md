# freesound-juce

A JUCE client for accessing the [Freesound](https://freesound.org) API. From the Freesound API docs:

> With the Freesound API you can browse, search, and retrieve information about Freesound users, packs, and the sounds themselves of course. You can find similar sounds to a given target (based on content analysis) and retrieve automatically extracted features from audio files, as well as perform advanced queries combining content analysis features and other metadata (tags, etc…). With the Freesound API, you can also upload, comment, rate and bookmark sounds!

The freesound-juce client automatically maps function arguments to HTTP parameters of the Freesound API. JSON results are parsed and converted to C++ objects. The main object classes (`SoundList`, `Sound`,
`User`, `Pack`) implement utility methods to further interact with the API.

The freesound-juce client includes a simple example command line application built with JUCE v5.4.4 which shows how to use it. Client's [documentation can be found here](https://mtg.github.io/freesound-juce/index.html). However we recommend you to check the [official Freesound API documentation]((https://freesound.org/docs/api/)) to get more information about the available API endpoints and features.


## Usage

To use freesound-juce just copy `FreesoundAPI.h` and `FreesoundAPI.cpp` to your project source folder and `#include "FreesoundAPI.h"`.

To access the API you'll need to create a Freesound user account and apply for an API key at [https://freesound.org/api/apply/](https://freesound.org/api/apply/). Then, an `FreesoundClient`
needs to be instantiated with the api key as a parameter. Note that this client can do both token-based
authentication or OAuth2 and there are specific functions for them.


## Quick example

```cpp
FreesoundClient client(secret);
SoundList list = client.textSearch("bass");
Array<FSSound> arrayOfSearch = list.toArrayOfSounds();
for (int i = 0; i < arrayOfSearch.size(); i++) {
  name = arrayOfSearch[i].name;
  username = arrayOfSearch[i].user;
  std::cout << "Sound Name: " << name << " Username: " << username << std::endl;
}

```


## Example applications

Check out this cool example apps:

 * [Demo app](https://github.com/aframires/freesound-juce/blob/master/Source/Main.cpp): simple command-line utility that makes some queries to Freesound to demonstrate how the client works. Includes OAuth2 authentication example as well.
 * [FreesoundUploader](https://github.com/aframires/FreesoundUploader): let's you upload sounds to Freesound directly from your DAW!

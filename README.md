# freesound-juce

A JUCE client for the Freesound API, built on JUCE v5.4.3.

Find the API documentation at http://www.freesound.org/docs/api/.

Apply for an API key at http://www.freesound.org/api/apply/.

The client automatically maps function arguments to http parameters of the API.
JSON results are converted to JUCE objects. The main object types (Sound,
User, Pack) are augmented with the corresponding API calls.

An extensive example on how to use this library can be seen in the [main file](https://github.com/aframires/freesound-juce/blob/master/Source/Main.cpp).

**Example usage:**

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
**Instalation:**
To install this library download the files and add them to your project in the Projucer:

* `FreesoundAPI.h`
* `FreesoundAPI.cpp`


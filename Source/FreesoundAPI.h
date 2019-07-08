/*
  ==============================================================================

    FreesoundAPI.h
    Created: 30 May 2019 12:49:28pm
    Author:  Antonio

  ==============================================================================
*/

//Todo - Comments

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

typedef std::pair<int, var> Response;
typedef std::function<void()> Callback;

class FSList {
private:
	int count;
	String nextPage;
	String previousPage;
	var results;
public:

	FSList();
	FSList(var response);

	String getNextPage();
	String getPreviousPage();

	var getResults();

};

class SoundList : public FSList{
	using FSList::FSList;
};

class URIS {

public:

	static String HOST;
	static String BASE;
	static String TEXT_SEARCH;
	static String CONTENT_SEARCH;
	static String COMBINED_SEARCH;
	static String SOUND;
	static String SOUND_ANALYSIS;
	static String SIMILAR_SOUNDS;
	static String COMMENTS;
	static String DOWNLOAD;
	static String UPLOAD;
	static String DESCRIBE;
	static String PENDING;
	static String BOOKMARK;
	static String RATE;
	static String COMMENT;
	static String AUTHORIZE;
	static String LOGOUT;
	static String LOGOUT_AUTHORIZE;
	static String ACCESS_TOKEN;
	static String ME;
	static String USER;
	static String USER_SOUNDS;
	static String USER_PACKS;
	static String USER_BOOKMARK_CATEGORIES;
	static String USER_BOOKMARK_CATEGORY_SOUNDS;
	static String PACK;
	static String PACK_SOUNDS;
	static String PACK_DOWNLOAD;
	static String CONFIRMATION;
	static String EDIT;

	URIS(){
	}

	~URIS() {
	}

	static URL uri(String uri, StringArray replacements = StringArray());
};

class FSUser {

public:
	URL profile;
	String username;
	String about;
	URL homepage;
	var avatar;
	String dateJoined;
	int numSounds;
	URL sounds;
	int numPacks;
	URL packs;
	int numPosts;
	int numComments;   
	URL bookmarks;

	FSUser();
	FSUser(var user);
};

class FSPack {

public:
	String id;
	URL url;
	String description;
	String created;
	String name;
	String username;
	int numSounds;
	URL sounds;
	int numDownloads;


	FSPack();
	FSPack(var pack);
	String getID();
};

class FSSound {
public:
	int id;
	URL url;
	String name;
	StringArray tags;
	String description;
	String geotag;
	String created;
	String license;
	String format;
	int channels;
	int filesize;
	int bitrate;
	int bitdepth;
	int duration;
	int samplerate;
	String user;
	URL pack;
	URL download;
	URL bookmark;
	var images;
	int numDownloads;
	float avgRating;
	int numRatings;
	URL rate;
	URL comments;
	int numComments;
	URL comment;
	URL similarSounds;
	var analysis;
	URL analysisStats;
	URL analysisFrames;
	var acAnalysis;

	FSSound();
	FSSound(var sound);
	URL getDownload();
};

class FreesoundClient{
	
private:


	enum Authorization
	{
		None,
		Token,
		OAuth
	};

	String token;
	String clientID;
	String clientSecret;
	String accessToken;
	String refreshToken;
	String header;
	Authorization auth;


public:
	FreesoundClient();
	//For token based authorization
	FreesoundClient(String secret);
	//For OAuth2 authorization
	FreesoundClient(String id, String secret);
	void authenticationOnBrowser(int mode=0, Callback cb = [] {});
	void exchangeToken(String authCode, Callback cb = [] {});
	void refreshAccessToken(Callback cb = [] {});
	SoundList textSearch(String query, String filter=String(), String sort="score", int groupByPack=0, int page=-1, int pageSize=-1, String fields = String(), String descriptors = String(), int normalized=0);
	SoundList contentSearch(String target, String descriptorsFilter=String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);
	SoundList fetchNextPage(SoundList soundList);
	SoundList fetchPreviousPage(SoundList soundList);
	FSSound getSound(String id);
	var getSoundAnalysis(String id, String descriptors = String(), int normalized = 0);
	SoundList getSimilarSounds(String id, String descriptorsFilter = String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);
	URL::DownloadTask* downloadSound(FSSound sound, const File &location, URL::DownloadTask::Listener * listener = nullptr);
	int uploadSound(const File &fileToUpload, String tags, String description, String name = String(), String license = "Creative Commons 0", String pack = String(), String geotag = String(), Callback cb = [] {});
	int describeSound(String uploadFilename, String description, String license, String name = String(), String tags = String(), String pack = String(), String geotag = String() );
	var pendingUploads();
	void editSoundDescription(String id, String name = String(), String tags = String(), String description = String(), String license = String(), String pack = String(), String geotag = String(), Callback cb = [] {});
	void bookmarkSound(String id, String name = String(), String category = String(), Callback cb = [] {});
	void rateSound(String id, int rating, Callback cb = [] {});
	void commentSound(String id, String comment, Callback cb = [] {});
	FSUser getUser(String user);
	SoundList getUserSounds(String username, String descriptorsFilter = String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);
	FSList getUserBookmarkCategories(String username);
	FSList getUserBookmarkCategoriesSounds(String username, String bookmarkCategory);
	FSList getUserPacks(String username);
	FSPack getPack(String id);
	SoundList getPackSounds(String id, String descriptorsFilter = String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);
	URL::DownloadTask* downloadPack(FSPack pack, const File &location, URL::DownloadTask::Listener * listener = nullptr);
	FSUser getMe();
	bool isTokenNotEmpty();
	String getToken();
	String getHeader();
	String getClientID();


};

class FreesoundClientComponent : public FreesoundClient, public WebBrowserComponent {
private:
	String authCode;
public:
	void startAuthentication(int mode = 0);
	void pageFinishedLoading(const String & url, Callback authCallback = [] {});
	void pageLoadHadNetworkError();

};

class FSRequest {
public:
	FSRequest(URL uriToRequest, FreesoundClient clientToUse)
		:client(clientToUse),
		uri(uriToRequest)
	{}
	
	Response request(StringPairArray params = StringPairArray(), String data = String(), bool postLikeRequest = true);

private:
	URL uri;
	FreesoundClient& client;
};

class FreesoundObject {
public:
	FreesoundObject(var inJsonDict, FreesoundClient& inClient)
		:client(inClient),
		jsonDict(inJsonDict)
	{}
private:
	FreesoundClient& client;
	var jsonDict;

};


#pragma once

//! \since 1.0
//! Implemented by components - register with playback_stream_capture methods.
class NOVTABLE playback_stream_capture_callback {
public:
	//! Delivers a real-time chunk of audio data. \n
	//! Audio is roughly synchronized with what can currently be heard. This API is provided for utility purposes such as streaming; if you want to implement a visualisation, use the visualisation_manager API instead. \n
	//! Called only from the main thread.
	virtual void on_chunk(const audio_chunk &) = 0;
protected:
	playback_stream_capture_callback() {}
	~playback_stream_capture_callback() {}
};

//! \since 1.0
//! Implemented by core.
class NOVTABLE playback_stream_capture : public service_base {
	FB2K_MAKE_SERVICE_COREAPI(playback_stream_capture)
public:
	//! Possible to call only from the main thread.
	virtual void add_callback(playback_stream_capture_callback * ) = 0;
	//! Possible to call only from the main thread.
	virtual void remove_callback(playback_stream_capture_callback * ) = 0;
};

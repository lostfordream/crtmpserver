/* 
 *  Copyright (c) 2010,
 *  Gavriloaie Eugen-Andrei (shiretu@gmail.com)
 *
 *  This file is part of crtmpserver.
 *  crtmpserver is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  crtmpserver is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with crtmpserver.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef _STRAMCAPABILITIES_H
#define	_STRAMCAPABILITIES_H

#include "streaming/codectypes.h"

struct _VIDEO_AVC {
	uint8_t *_pSPS;
	uint16_t _spsLength;
	uint8_t *_pPPS;
	uint16_t _ppsLength;
	uint32_t _rate;

	_VIDEO_AVC();
	virtual ~_VIDEO_AVC();
	bool Init(uint8_t *pSPS, uint32_t spsLength, uint8_t *pPPS, uint32_t ppsLength);
	void Clear();

	operator string();
};

struct _AUDIO_AAC {
	uint8_t *_pAAC;
	uint32_t _aacLength;
	uint8_t _audioObjectType;
	uint8_t _sampleRateIndex;
	uint32_t _sampleRate;
	uint8_t _channelConfigurationIndex;

	_AUDIO_AAC();
	virtual ~_AUDIO_AAC();
	bool Init(uint8_t *pBuffer, uint32_t length);
	void Clear();
	string GetRTSPFmtpConfig();

	operator string();
};

class StreamCapabilities {
public:
	uint64_t videoCodecId;
	uint64_t audioCodecId;
	_VIDEO_AVC avc;
	_AUDIO_AAC aac;
public:
	StreamCapabilities();
	virtual ~StreamCapabilities();

	bool InitAudioAAC(uint8_t *pBuffer, uint32_t length);
	bool InitVideoH264(uint8_t *pSPS, uint32_t spsLength, uint8_t *pPPS, uint32_t ppsLength);

	void ClearVideo();
	void ClearAudio();
	void Clear();
};

#endif	/* _STRAMCAPABILITIES_H */


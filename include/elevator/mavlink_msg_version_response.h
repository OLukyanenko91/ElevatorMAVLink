#pragma once
// MESSAGE VERSION_RESPONSE PACKING

#define MAVLINK_MSG_ID_VERSION_RESPONSE 60001


typedef struct __mavlink_version_response_t {
 char sw_version[10]; /*<  Software version.*/
 char mavlink_dialect_version[10]; /*<  MAVLink dialect version.*/
} mavlink_version_response_t;

#define MAVLINK_MSG_ID_VERSION_RESPONSE_LEN 20
#define MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN 20
#define MAVLINK_MSG_ID_60001_LEN 20
#define MAVLINK_MSG_ID_60001_MIN_LEN 20

#define MAVLINK_MSG_ID_VERSION_RESPONSE_CRC 74
#define MAVLINK_MSG_ID_60001_CRC 74

#define MAVLINK_MSG_VERSION_RESPONSE_FIELD_SW_VERSION_LEN 10
#define MAVLINK_MSG_VERSION_RESPONSE_FIELD_MAVLINK_DIALECT_VERSION_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VERSION_RESPONSE { \
    60001, \
    "VERSION_RESPONSE", \
    2, \
    {  { "sw_version", NULL, MAVLINK_TYPE_CHAR, 10, 0, offsetof(mavlink_version_response_t, sw_version) }, \
         { "mavlink_dialect_version", NULL, MAVLINK_TYPE_CHAR, 10, 10, offsetof(mavlink_version_response_t, mavlink_dialect_version) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VERSION_RESPONSE { \
    "VERSION_RESPONSE", \
    2, \
    {  { "sw_version", NULL, MAVLINK_TYPE_CHAR, 10, 0, offsetof(mavlink_version_response_t, sw_version) }, \
         { "mavlink_dialect_version", NULL, MAVLINK_TYPE_CHAR, 10, 10, offsetof(mavlink_version_response_t, mavlink_dialect_version) }, \
         } \
}
#endif

/**
 * @brief Pack a version_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sw_version  Software version.
 * @param mavlink_dialect_version  MAVLink dialect version.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_version_response_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *sw_version, const char *mavlink_dialect_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VERSION_RESPONSE_LEN];

    _mav_put_char_array(buf, 0, sw_version, 10);
    _mav_put_char_array(buf, 10, mavlink_dialect_version, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN);
#else
    mavlink_version_response_t packet;

    mav_array_memcpy(packet.sw_version, sw_version, sizeof(char)*10);
    mav_array_memcpy(packet.mavlink_dialect_version, mavlink_dialect_version, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VERSION_RESPONSE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_CRC);
}

/**
 * @brief Pack a version_response message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param sw_version  Software version.
 * @param mavlink_dialect_version  MAVLink dialect version.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_version_response_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               const char *sw_version, const char *mavlink_dialect_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VERSION_RESPONSE_LEN];

    _mav_put_char_array(buf, 0, sw_version, 10);
    _mav_put_char_array(buf, 10, mavlink_dialect_version, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN);
#else
    mavlink_version_response_t packet;

    mav_array_memcpy(packet.sw_version, sw_version, sizeof(char)*10);
    mav_array_memcpy(packet.mavlink_dialect_version, mavlink_dialect_version, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VERSION_RESPONSE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN);
#endif
}

/**
 * @brief Pack a version_response message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sw_version  Software version.
 * @param mavlink_dialect_version  MAVLink dialect version.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_version_response_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *sw_version,const char *mavlink_dialect_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VERSION_RESPONSE_LEN];

    _mav_put_char_array(buf, 0, sw_version, 10);
    _mav_put_char_array(buf, 10, mavlink_dialect_version, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN);
#else
    mavlink_version_response_t packet;

    mav_array_memcpy(packet.sw_version, sw_version, sizeof(char)*10);
    mav_array_memcpy(packet.mavlink_dialect_version, mavlink_dialect_version, sizeof(char)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VERSION_RESPONSE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_CRC);
}

/**
 * @brief Encode a version_response struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param version_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_version_response_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_version_response_t* version_response)
{
    return mavlink_msg_version_response_pack(system_id, component_id, msg, version_response->sw_version, version_response->mavlink_dialect_version);
}

/**
 * @brief Encode a version_response struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param version_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_version_response_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_version_response_t* version_response)
{
    return mavlink_msg_version_response_pack_chan(system_id, component_id, chan, msg, version_response->sw_version, version_response->mavlink_dialect_version);
}

/**
 * @brief Encode a version_response struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param version_response C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_version_response_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_version_response_t* version_response)
{
    return mavlink_msg_version_response_pack_status(system_id, component_id, _status, msg,  version_response->sw_version, version_response->mavlink_dialect_version);
}

/**
 * @brief Send a version_response message
 * @param chan MAVLink channel to send the message
 *
 * @param sw_version  Software version.
 * @param mavlink_dialect_version  MAVLink dialect version.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_version_response_send(mavlink_channel_t chan, const char *sw_version, const char *mavlink_dialect_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VERSION_RESPONSE_LEN];

    _mav_put_char_array(buf, 0, sw_version, 10);
    _mav_put_char_array(buf, 10, mavlink_dialect_version, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VERSION_RESPONSE, buf, MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_CRC);
#else
    mavlink_version_response_t packet;

    mav_array_memcpy(packet.sw_version, sw_version, sizeof(char)*10);
    mav_array_memcpy(packet.mavlink_dialect_version, mavlink_dialect_version, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VERSION_RESPONSE, (const char *)&packet, MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_CRC);
#endif
}

/**
 * @brief Send a version_response message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_version_response_send_struct(mavlink_channel_t chan, const mavlink_version_response_t* version_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_version_response_send(chan, version_response->sw_version, version_response->mavlink_dialect_version);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VERSION_RESPONSE, (const char *)version_response, MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_CRC);
#endif
}

#if MAVLINK_MSG_ID_VERSION_RESPONSE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_version_response_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *sw_version, const char *mavlink_dialect_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_char_array(buf, 0, sw_version, 10);
    _mav_put_char_array(buf, 10, mavlink_dialect_version, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VERSION_RESPONSE, buf, MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_CRC);
#else
    mavlink_version_response_t *packet = (mavlink_version_response_t *)msgbuf;

    mav_array_memcpy(packet->sw_version, sw_version, sizeof(char)*10);
    mav_array_memcpy(packet->mavlink_dialect_version, mavlink_dialect_version, sizeof(char)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VERSION_RESPONSE, (const char *)packet, MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN, MAVLINK_MSG_ID_VERSION_RESPONSE_CRC);
#endif
}
#endif

#endif

// MESSAGE VERSION_RESPONSE UNPACKING


/**
 * @brief Get field sw_version from version_response message
 *
 * @return  Software version.
 */
static inline uint16_t mavlink_msg_version_response_get_sw_version(const mavlink_message_t* msg, char *sw_version)
{
    return _MAV_RETURN_char_array(msg, sw_version, 10,  0);
}

/**
 * @brief Get field mavlink_dialect_version from version_response message
 *
 * @return  MAVLink dialect version.
 */
static inline uint16_t mavlink_msg_version_response_get_mavlink_dialect_version(const mavlink_message_t* msg, char *mavlink_dialect_version)
{
    return _MAV_RETURN_char_array(msg, mavlink_dialect_version, 10,  10);
}

/**
 * @brief Decode a version_response message into a struct
 *
 * @param msg The message to decode
 * @param version_response C-struct to decode the message contents into
 */
static inline void mavlink_msg_version_response_decode(const mavlink_message_t* msg, mavlink_version_response_t* version_response)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_version_response_get_sw_version(msg, version_response->sw_version);
    mavlink_msg_version_response_get_mavlink_dialect_version(msg, version_response->mavlink_dialect_version);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VERSION_RESPONSE_LEN? msg->len : MAVLINK_MSG_ID_VERSION_RESPONSE_LEN;
        memset(version_response, 0, MAVLINK_MSG_ID_VERSION_RESPONSE_LEN);
    memcpy(version_response, _MAV_PAYLOAD(msg), len);
#endif
}

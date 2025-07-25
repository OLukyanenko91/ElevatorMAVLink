/** @file
 *    @brief MAVLink comm protocol testsuite generated from elevator.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef ELEVATOR_TESTSUITE_H
#define ELEVATOR_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_ardupilotmega(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_elevator(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_ardupilotmega(system_id, component_id, last_msg);
    mavlink_test_elevator(system_id, component_id, last_msg);
}
#endif

#include "../ardupilotmega/testsuite.h"


static void mavlink_test_version_response(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_VERSION_RESPONSE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_version_response_t packet_in = {
        "ABCDEFGHI","KLMNOPQRS"
    };
    mavlink_version_response_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.sw_version, packet_in.sw_version, sizeof(char)*10);
        mav_array_memcpy(packet1.mavlink_dialect_version, packet_in.mavlink_dialect_version, sizeof(char)*10);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_VERSION_RESPONSE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_version_response_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_version_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_version_response_pack(system_id, component_id, &msg , packet1.sw_version , packet1.mavlink_dialect_version );
    mavlink_msg_version_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_version_response_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.sw_version , packet1.mavlink_dialect_version );
    mavlink_msg_version_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_version_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_version_response_send(MAVLINK_COMM_1 , packet1.sw_version , packet1.mavlink_dialect_version );
    mavlink_msg_version_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("VERSION_RESPONSE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_VERSION_RESPONSE) != NULL);
#endif
}

static void mavlink_test_elevator(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_version_response(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ELEVATOR_TESTSUITE_H

/** @file
 *	@brief MAVLink comm testsuite protocol generated from elevator.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "elevator.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(elevator, VERSION_RESPONSE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::elevator::msg::VERSION_RESPONSE packet_in{};
    packet_in.sw_version = to_char_array("ABCDEFGHI");
    packet_in.mavlink_dialect_version = to_char_array("KLMNOPQRS");

    mavlink::elevator::msg::VERSION_RESPONSE packet1{};
    mavlink::elevator::msg::VERSION_RESPONSE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.sw_version, packet2.sw_version);
    EXPECT_EQ(packet1.mavlink_dialect_version, packet2.mavlink_dialect_version);
}

#ifdef TEST_INTEROP
TEST(elevator_interop, VERSION_RESPONSE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_version_response_t packet_c {
         "ABCDEFGHI", "KLMNOPQRS"
    };

    mavlink::elevator::msg::VERSION_RESPONSE packet_in{};
    packet_in.sw_version = to_char_array("ABCDEFGHI");
    packet_in.mavlink_dialect_version = to_char_array("KLMNOPQRS");

    mavlink::elevator::msg::VERSION_RESPONSE packet2{};

    mavlink_msg_version_response_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.sw_version, packet2.sw_version);
    EXPECT_EQ(packet_in.mavlink_dialect_version, packet2.mavlink_dialect_version);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

// MESSAGE VERSION_RESPONSE support class

#pragma once

namespace mavlink {
namespace elevator {
namespace msg {

/**
 * @brief VERSION_RESPONSE message
 *
 * Response to version request.
 */
struct VERSION_RESPONSE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 60001;
    static constexpr size_t LENGTH = 20;
    static constexpr size_t MIN_LENGTH = 20;
    static constexpr uint8_t CRC_EXTRA = 74;
    static constexpr auto NAME = "VERSION_RESPONSE";


    std::array<char, 10> sw_version; /*<  Software version. */
    std::array<char, 10> mavlink_dialect_version; /*<  MAVLink dialect version. */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  sw_version: \"" << to_string(sw_version) << "\"" << std::endl;
        ss << "  mavlink_dialect_version: \"" << to_string(mavlink_dialect_version) << "\"" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << sw_version;                    // offset: 0
        map << mavlink_dialect_version;       // offset: 10
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> sw_version;                    // offset: 0
        map >> mavlink_dialect_version;       // offset: 10
    }
};

} // namespace msg
} // namespace elevator
} // namespace mavlink

#include "main.h"
#include <dpp/dpp.h>
#include <string>
#include <algorithm>

const std::string BOT_TOKEN = "MTE0MjIyNjg4OTc0Njk2MDQxNQ.GmdFbF.cb9F1Sk9J9zUCq7xNykIY7966trJ1bd6pTjOi4";

int main() 
{
    dpp::cluster bot(BOT_TOKEN);

    bot.on_log(dpp::utility::cout_logger());
    bot.intents = dpp::i_message_content;

    bot.on_slashcommand([](const dpp::slashcommand_t& event)
        {
            if (event.command.get_command_name() == "ping")
            {
                event.reply("Pong!");
            }
        });

    bot.on_ready([&bot](const dpp::ready_t& event)
        {
            if (dpp::run_once<struct register_bot_commands>())
            {
                bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
            }
        });

    bot.on_message_create([&bot](const dpp::message_create_t& event)
        {
            std::string message = event.msg.content;
            std::transform(message.begin(), message.end(), message.begin(), ::tolower);

            if (message.find("ne"))
            {
                event.reply("NENENÝN BURNUNU YEEEEEE");
            }
        });

    bot.start(dpp::st_wait);
}
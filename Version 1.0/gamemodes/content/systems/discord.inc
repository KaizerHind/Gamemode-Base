/*
# Credits of format embeds to Amosmoses.
*/

SendJoinEmbedMessage(const channel[], const message[])
{
    new DCC_Embed:embed = DCC_CreateEmbed("Conectado");

    ChannelBot = DCC_FindChannelById(channel);

    DCC_SetEmbedColor(embed, DC_COL_GREEN),
    DCC_SetEmbedDescription(embed, message);

    DCC_SendChannelEmbedMessage(ChannelBot, embed);
    return 1;
}

SendGetOutEmbedMessage(const channel[], const message[])
{
    new DCC_Embed:embed = DCC_CreateEmbed("Desconectado");

    ChannelBot = DCC_FindChannelById(channel);

    DCC_SetEmbedColor(embed, DC_COL_RED),
    DCC_SetEmbedDescription(embed, message);

    DCC_SendChannelEmbedMessage(ChannelBot, embed);
    return 1;
}

SendRegisterEmbedMessage(const channel[], const message[])
{
    new DCC_Embed:embed = DCC_CreateEmbed("Registrandose");

    ChannelBot = DCC_FindChannelById(channel);

    DCC_SetEmbedColor(embed, DC_COL_ORANGE),
    DCC_SetEmbedDescription(embed, message);

    DCC_SendChannelEmbedMessage(ChannelBot, embed);
    return 1;
}

SendOnLineEmbedMessage(const channel[], const message[])
{
    new DCC_Embed:embed = DCC_CreateEmbed("Servidor en Linea");

    ChannelBot = DCC_FindChannelById(channel);

    DCC_SetEmbedColor(embed, DC_COL_SERVER),
    DCC_SetEmbedDescription(embed, message);

    DCC_SendChannelEmbedMessage(ChannelBot, embed);
    return 1;
}

SendRolTestEmbedMessage(const channel[], const message[])
{
    new DCC_Embed:embed = DCC_CreateEmbed("Certificacion de Rol");

    ChannelBot = DCC_FindChannelById(channel);

    DCC_SetEmbedColor(embed, DC_COL_SERVER),
    DCC_SetEmbedDescription(embed, message);

    DCC_SendChannelEmbedMessage(ChannelBot, embed);
    return 1;
}

public DCC_OnMessageCreate(DCC_Message:message) 
{

    new DCC_Channel:channel;
    DCC_GetMessageChannel(message, channel);

    if (channel != ChannelBot)
        return 1;

    new DCC_User:author;
    DCC_GetMessageAuthor(message, author);


    new bool:isBot;
    DCC_IsUserBot(author, isBot);

    if (isBot) {return 1;}
    return 1;
}
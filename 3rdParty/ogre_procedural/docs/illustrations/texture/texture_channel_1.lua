buffer = Procedural.TextureBuffer(128)
Procedural.Image(buffer):setFile("red_brick.jpg"):process()
Procedural.Channel(buffer):setSelection(Procedural.Channel_SELECT_BLUE):process()
tests:addTextureBuffer(buffer)
dotfile = tests:getDotFile("texture_06a", "Channel_blue_Demo")
dotfile:set("Image", "texture_image", "Channel", "texture_channel_1")

// Copyright (c) Facebook, Inc. and its affiliates. All Rights Reserved
#version 430 core

layout(location = 0) in vec4 position;
uniform mat4 MVP_current;
uniform mat4 MVP_next;

out vec4 pos_next;

out gl_PerVertex {
    smooth vec4 gl_Position;
};

void main()
{
    gl_Position = MVP_current * position;
    pos_next = MVP_next * position;
}

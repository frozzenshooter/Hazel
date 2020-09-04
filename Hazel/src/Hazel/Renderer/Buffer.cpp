#include "hzpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Hazel {

    VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) 
    {
        switch (Renderer::GetAPI()) {
            case RendererAPI::API::None:   HZ_CORE_ASSERT(false, "RendererAPI::NONE is currently not supported"); return nullptr;
            case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
        }

        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indicies, uint32_t size)
    {
        switch (Renderer::GetAPI()) {
        case RendererAPI::API::None:   HZ_CORE_ASSERT(false, "RendererAPI::NONE is currently not supported"); return nullptr;
        case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indicies, size);
        }

        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
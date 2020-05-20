#include "rbpch.h"
#include "SubTexture2D.h"

namespace Rainbow {
	SubTexture2D::SubTexture2D(const Ref<Texture2D>& texture, const glm::vec2& min, const glm::vec2& max)
		: m_Texture(texture)
	{
		m_TexCoords[0] = {min.x, min.y};
		m_TexCoords[1] = {max.x, min.y};
		m_TexCoords[2] = {max.x, max.y};
		m_TexCoords[3] = {min.x, max.y};
	}

	Ref<SubTexture2D> SubTexture2D::CreateFromCoords(const Ref<Texture2D>& texture, const glm::vec2& coords, const glm::vec2& cellSize, const glm::vec2& spriteSize, const float gapSize)
	{

		glm::vec2 min = { (coords.x * (cellSize.x + gapSize)) / texture->GetWidth(), (coords.y * (cellSize.y + gapSize)) / texture->GetHeight() };
		glm::vec2 max = { ((coords.x + spriteSize.x) * cellSize.x + coords.x * gapSize) / texture->GetWidth(), ((coords.y + spriteSize.y) * cellSize.y + coords.y * gapSize) / texture->GetHeight() };
		return CreateRef<SubTexture2D>(texture, min, max);
		
	}

}

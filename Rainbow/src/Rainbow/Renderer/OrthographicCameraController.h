#pragma once

#include "Rainbow/Renderer/OrthographicCamera.h"
#include "Rainbow/Core/Timestep.h"

#include "Rainbow/Events/ApplicationEvent.h"
#include "Rainbow/Events/MouseEvent.h"

namespace Rainbow {


	struct OrthographicCameraBounds
	{
		float Left, Right;
		float Bottom, Top;

		float GetWidth() { return Right - Left; }
		float GetHeight() { return Top - Bottom; }
	};

	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectratio, bool rotation = false);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const { return m_Camera; }
		float GetZoomLevel() const { return m_ZoomLevel; }
		void SetZoomLevel(float zoomLevel) { m_ZoomLevel = zoomLevel; CalculateView(); }

		const OrthographicCameraBounds& GetBounds() const { return m_Bounds; }
		
	private:
		void CalculateView();
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);

		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographicCameraBounds m_Bounds;
		OrthographicCamera m_Camera;

		bool m_Rotation;
		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f; //degrees anti-clockwise
		float m_CameraTranslationSpeed = 1.0f, m_CameraRotationSpeed = 135.0f;

	};


}
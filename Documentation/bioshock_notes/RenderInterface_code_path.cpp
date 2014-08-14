class ENGINE_API FRenderInterface
{
public:
	// Scene Management
	virtual FSceneRenderInterface* QuerySceneRenderInterface() = 0;
	virtual void ReleaseSceneRenderInterface(FSceneRenderInterface* SceneRenderInterface) = 0;

	virtual FBatchInterface* BeginBatch(FCommandState* CommandState) = 0;
	virtual void EndBatch() = 0;

	virtual void BeginShadowBufferRender(const FIntRect& DestRect) = 0;
	virtual void EndShadowBufferRender() = 0;

    virtual void BeginTopWaterBufferRender() = 0;
    virtual void BeginBottomWaterBufferRender() = 0;
    virtual void EndTopWaterBufferRender() = 0;
    virtual void EndBottomWaterBufferRender() = 0;

	virtual void BeginRippleMaskRendering(BYTE inStencilRef) = 0;
	virtual void EndRippleMaskRendering() = 0;

	virtual void BeginRenderingUsingRippleMask(BYTE inStencilRef) = 0;
	virtual void EndRenderingUsingRippleMask() = 0;

	virtual void PushHit(const BYTE* Data,INT Count) = 0;
	virtual void PopHit(INT Count,UBOOL Force) = 0;

	virtual void FlushGPU() = 0;

	virtual void ProcessCallbacks() = 0;
	// Surfaces
	virtual UBOOL SetRenderTarget(FRenderTarget* RenderTarget) = 0;
	virtual void SetViewport(INT X,INT Y,INT Width,INT Height,FLOAT MinZ=0.0f, FLOAT MaxZ=1.0f) = 0;
	virtual void SetViewportZ(FLOAT MinZ, FLOAT MaxZ) {}
	virtual void Clear(UBOOL UseColor = 1,FColor Color = FColor(0,0,0),UBOOL UseDepth = 1,FLOAT Depth = 1.0f,UBOOL UseStencil = 1,DWORD Stencil = 0) = 0;
	virtual INT  GetScissorWidth() = 0;
	virtual INT  GetScissorHeight() = 0;
	virtual void SetScissorEnable(UBOOL) = 0;

	// Materials
	virtual void SetEmptyShader() = 0;
	virtual void SetCanvasShader(const class FCanvasShaderData& ShaderData) = 0;
	virtual void SetBaseShader(const class FBaseShaderData& ShaderData, UBOOL bBindData = TRUE) = 0;
	virtual void SetLayerLightShader(const class FLayerLightShaderData& ShaderData, UBOOL bBindData = TRUE) = 0;
	virtual void SetDynamicLightShader(const class FDynamicLightShaderData& ShaderData) = 0;
	virtual void SetGlobalLightShader(const class FDynamicLightShaderData& ShaderData) = 0;
    virtual void SetReflectionShader(const class FReflectionShaderData& ShaderData) = 0;
	virtual void SetParticleShader(const class FParticleShaderData& ShaderData) = 0;
	virtual void SetDepthShadowShader(const class FDepthShaderData& ShaderData) = 0;
	virtual void SetDepthWaterShader(const class FDepthShaderData& ShaderData) = 0;
    virtual void SetRippleShader(const class FRippleShaderData& ShaderData) = 0;
    virtual void SetRippleMaskShader(const class FRippleMaskShaderData& ShaderData) = 0;
	virtual void SetPostProcessShader(const class FPostProcessEffectShaderData& ShaderData) = 0;

	// Render State
	virtual void SetCullMode(ECullMode CullMode) = 0;
	virtual void SetWireframe(UBOOL Wireframe) = 0;
	virtual void SetTransform(ETransformType Type, const FMatrix& Matrix) = 0;
	virtual void SetLocalTransform(const FMatrix& LocalToWorld, const FMatrix& WorldToLocal) = 0;
	virtual void SetStencilOp(ECompareFunction Test,DWORD Ref,DWORD Mask,EStencilOp FailOp,EStencilOp ZFailOp,EStencilOp PassOp,DWORD WriteMask) = 0;
	virtual void SetZBias(INT ZBias) = 0;
	virtual void SetFog(UBOOL Enable, const FSceneFog* Fog) = 0;
	virtual void SetGlobalOpacity(EGlobalOpacityType OpacityType, UBOOL UsePerVertexOpacity, FLOAT Opacity) = 0;
	virtual void SetClipPlanes(const FClipPlanes* ClipPlanes, const FMatrix& WorldToScreen) = 0;	// Pass NULL to disable clip planes
	virtual void SetColorWrite(UBOOL R, UBOOL G, UBOOL B, UBOOL A) = 0;
	virtual void SetBlendEnable( UBOOL Enable ) = 0 ;
	virtual void SetBlendFunc ( UINT SrcFunc , UINT DestFunc ) = 0 ; 
	virtual void SetBoneMatrices(FPlane &BoneMatrices,int count)=0;

	// Stream State
	virtual void SetVertexStreams(const FVertexFactory* VertexFactory,FVertexStream** Streams, INT* Offsets,INT* DeclarationIndexes, INT NumStreams) = 0;
	virtual INT SetDynamicStream(const FVertexFactory* VertexFactory,FVertexStream* Stream) = 0;
	virtual INT SetDynamicStreamUpdate(const FVertexFactory* VertexFactory,FVertexStream* Stream) { return 0; }
	virtual INT SetDynamicStreamSubmit(const FVertexFactory* VertexFactory,FVertexStream* Stream) { return 0; }
	virtual void SetIndexBuffer(FIndexBuffer* IndexBuffer,INT BaseIndex) = 0;
	virtual INT SetDynamicIndexBuffer(FIndexBuffer* IndexBuffer,INT BaseIndex) = 0;

	// Allows platform specific acceleration of dynamic vertex stream upload
	virtual void UploadDynamicVertexStreams(FVertexStream** VertexStreams, UINT VertexStreamCount) = 0;
	virtual void DynamicVertexStreamsUpdate(FVertexStream** VertexStreams, UINT VertexStreamCount) {}
	virtual void DynamicVertexStreamsSubmit(FVertexStream** VertexStreams, UINT VertexStreamCount) {}

	// Draw
	virtual void DrawPrimitive(EPrimitiveType PrimitiveType,INT FirstIndex,INT NumPrimitives,INT MinIndex = INDEX_NONE,INT MaxIndex = INDEX_NONE) = 0;
	virtual void DrawPrimitiveUP(EPrimitiveType PrimitiveType,INT NumPrimitives,const void* pVertices,const FVertexComponent* Components,UINT ComponentCount) = 0;
	virtual void DrawDepthShadow(const class FDepthInfo& Info, const FVector& ViewOrigin,bool IsSpotLight=true)=0;
	virtual void DrawFogPortal(const class FFogPortalInfo& Element, const FVector& ViewOrigin) = 0;
	virtual void DrawWaterSimulation(float inDeltaTime) = 0;

	// Multithreading, other functions might fail if called in a thread that does not have ownership.
	virtual void AcquireThreadOwnership() = 0;
	virtual void ReleaseThreadOwnership() = 0;

	// precaching Shaders
	virtual void CompileShaderState(UBOOL bForceCompile) = 0;
	virtual void SetVertexFactory( const FVertexFactory* VertexFactory ) = 0;

	virtual void SubmitOcclusionQueries(FDynamicActor** Actors, INT ActorCount) {}

	virtual void ResetState() {};
	virtual void LogState() {};
};

/***************************************************************************
***************************************************************************/
class FES2RenderInterface : public FRenderInterface
{
public:
	class FES2ViewportState
	{
	public:
		FSurfaceRHIParamRef	RenderTargetSurface;
		FSurfaceRHIParamRef	DepthStencilSurface;

		UINT MinX;
		UINT MinY;
		FLOAT MinZ;
		UINT Width;
		UINT Height;
		FLOAT MaxZ;

		ECullMode		CullMode;		
	};

	FES2RenderInterface(UES2RenderDevice* InRenDev);
	~FES2RenderInterface();

	// Scene Management
	virtual FSceneRenderInterface* QuerySceneRenderInterface();
	virtual void ReleaseSceneRenderInterface(FSceneRenderInterface* SceneRenderInterface){}

	virtual FBatchInterface* BeginBatch(FCommandState* CommandState);
	virtual void EndBatch();

	virtual void BeginShadowBufferRender(const FIntRect& DestRect);
	virtual void EndShadowBufferRender();

	virtual void BeginTopWaterBufferRender(){}
	virtual void BeginBottomWaterBufferRender(){}
	virtual void EndTopWaterBufferRender(){}
	virtual void EndBottomWaterBufferRender(){}

	virtual void BeginRippleMaskRendering(BYTE inStencilRef){}
	virtual void EndRippleMaskRendering(){}

	virtual void BeginRenderingUsingRippleMask(BYTE inStencilRef){}
	virtual void EndRenderingUsingRippleMask(){}

	virtual void PushHit(const BYTE* Data,INT Count){}
	virtual void PopHit(INT Count,UBOOL Force){}

	virtual void FlushGPU(){}

	virtual void ProcessCallbacks();
	// Surfaces
	virtual UBOOL SetRenderTarget(FRenderTarget* RenderTarget);
	virtual void SetViewport(INT X,INT Y,INT Width,INT Height,FLOAT MinZ=0.0f, FLOAT MaxZ=1.0f);
	virtual void SetViewportZ(FLOAT MinZ, FLOAT MaxZ);
	virtual void Clear(UBOOL UseColor = 1,FColor Color = FColor(0,0,0),UBOOL UseDepth = 1,FLOAT Depth = 1.0f,UBOOL UseStencil = 1,DWORD Stencil = 0);
	virtual INT  GetScissorWidth();
	virtual INT  GetScissorHeight();
	virtual void SetScissorEnable(UBOOL State);

	// Materials
	virtual void SetEmptyShader();
	virtual void SetCanvasShader(const class FCanvasShaderData& ShaderData);
	virtual void SetBaseShader(const class FBaseShaderData& ShaderData, UBOOL bBindData = TRUE);
	virtual void SetLayerLightShader(const class FLayerLightShaderData& ShaderData, UBOOL bBindData = TRUE);
	virtual void SetDynamicLightShader(const class FDynamicLightShaderData& ShaderData);
	virtual void SetGlobalLightShader(const class FDynamicLightShaderData& ShaderData);
	virtual void SetReflectionShader(const class FReflectionShaderData& ShaderData);
	virtual void SetParticleShader(const class FParticleShaderData& ShaderData);
	virtual void SetDepthShadowShader(const class FDepthShaderData& ShaderData);
	virtual void SetDepthWaterShader(const class FDepthShaderData& ShaderData);
	virtual void SetRippleShader(const class FRippleShaderData& ShaderData);
	virtual void SetRippleMaskShader(const class FRippleMaskShaderData& ShaderData);
	virtual void SetPostProcessShader(const class FPostProcessEffectShaderData& ShaderData);

	// Render State
	virtual void SetCullMode(ECullMode CullMode);
	virtual void SetWireframe(UBOOL Wireframe);
	virtual void SetTransform(ETransformType Type, const FMatrix& Matrix);
	virtual void SetLocalTransform(const FMatrix& LocalToWorld, const FMatrix& WorldToLocal);
	virtual void SetStencilOp(ECompareFunction Test,DWORD Ref,DWORD Mask,EStencilOp FailOp,EStencilOp ZFailOp,EStencilOp PassOp,DWORD WriteMask);
	virtual void SetZBias(INT ZBias);
	virtual void SetFog(UBOOL Enable, const FSceneFog* Fog);
	virtual void SetGlobalOpacity(EGlobalOpacityType OpacityType, UBOOL UsePerVertexOpacity, FLOAT Opacity);
	virtual void SetClipPlanes(const FClipPlanes* ClipPlanes, const FMatrix& WorldToScreen);
	virtual void SetColorWrite(UBOOL R, UBOOL G, UBOOL B, UBOOL A);
	virtual void SetBlendEnable( UBOOL Enable ) ;
	virtual void SetBlendFunc ( UINT SrcFunc , UINT DestFunc ) ;
	virtual void SetBoneMatrices(FPlane &BoneMatrices,int count);

	// Stream State
	virtual void SetVertexStreams(const FVertexFactory* VertexFactory,FVertexStream** Streams, INT* Offsets,INT* DeclarationIndexes, INT NumStreams);
	virtual INT SetDynamicStream(const FVertexFactory* VertexFactory,FVertexStream* Stream);
	virtual INT SetDynamicStreamUpdate(const FVertexFactory* VertexFactory,FVertexStream* Stream);
	virtual INT SetDynamicStreamSubmit(const FVertexFactory* VertexFactory,FVertexStream* Stream);
	virtual void SetIndexBuffer(FIndexBuffer* IndexBuffer,INT BaseIndex);
	virtual INT SetDynamicIndexBuffer(FIndexBuffer* IndexBuffer,INT BaseIndex);

	// Allows platform specific acceleration of dynamic vertex stream upload

	virtual void UploadDynamicVertexStreams(FVertexStream** VertexStreams, UINT VertexStreamCount) ;
	virtual void DynamicVertexStreamsUpdate(FVertexStream** VertexStreams, UINT VertexStreamCount) ;
	virtual void DynamicVertexStreamsSubmit(FVertexStream** VertexStreams, UINT VertexStreamCount) ;
	// Draw
	virtual void DrawPrimitive(EPrimitiveType PrimitiveType,INT FirstIndex,INT NumPrimitives,INT MinIndex = INDEX_NONE,INT MaxIndex = INDEX_NONE);
	virtual void DrawPrimitiveUP(EPrimitiveType PrimitiveType,INT NumPrimitives,const void* pVertices,const FVertexComponent* Components,UINT ComponentCount);
	virtual void DrawDepthShadow(const class FDepthInfo& Info, const FVector& ViewOrigin,bool IsSpotLight=true);
	virtual void DrawFogPortal(const class FFogPortalInfo& Element, const FVector& ViewOrigin);
	virtual void DrawWaterSimulation(float inDeltaTime){}

	// Multithreading, other functions might fail if called in a thread that does not have ownership.
	virtual void AcquireThreadOwnership();
	virtual void ReleaseThreadOwnership();

	// precaching Shaders
	void CompileShaderState(UBOOL bForceCompile);
	virtual void SetVertexFactory( const FVertexFactory* VertexFactory ){}

	// FES2RenderInterface interface.
	void Locked( UViewport* InViewport, BYTE* InHitData,INT* InHitSize);
	void Unlocked();

	void GetCurrentPassInfo(FShaderPassInfo& Output);
	void RestoreViewport();

	void PushViewportState();
	void PopViewportState();

protected:
	void SetupVertexAttribArray		( FStreamDeclaration &Stream, const void* pVertices, UINT Offset, UINT Stride );
	void SetupVertexAttribArrayVBO	( FStreamDeclaration &Stream, UINT Offset, UINT Stride );

public:
	UES2RenderDevice*			RenDev;
	UViewport*					Viewport;
	FES2RIState					CurrentState;
	FMaterialInstance			DefaultMaterialInstance;

	FES2SceneRenderInterface*	SceneRenderInterface;
	TM::FTransformManager*		TransformManager;
	FES2BatchInterface*			BatchInterface;
	FPostPixelShaderProcessor*	PostPixelShaderProcessor;

	#define MAX_VIEWPORTSTACK 16
	FES2ViewportState		ViewportState;
	FES2ViewportState		SavedViewportState[MAX_VIEWPORTSTACK];
	int						SavedViewportStateIndex;

	// Hit stack.
	TArray<BYTE>			HitStack;
	BYTE*					HitData;
	INT*					HitSize;
	INT						HitCount;
	DWORD					HitPixels[HIT_SIZE][HIT_SIZE];
private :
	void SetMaterialBlending( FES2MaterialState& NewMaterialState, class FCommandState* CommandState = NULL );
	void ReleasePreviousMaterialState();

	friend class FES2BatchInterface;
};
